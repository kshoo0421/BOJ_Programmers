#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<int> parent(n + 1), rank(n + 1, 0);
    for(int i = 1; i <= n; i++) parent[i] = i;
    
    function<int(int)> FindParent = [&](int a) {
        if(parent[a] == a) return a;
        return parent[a] = FindParent(parent[a]);
    };
    
    function<void(int, int)> SetUnion = [&](int x, int y) {
        int rootX = FindParent(x);
        int rootY = FindParent(y);
        
        if(rootX != rootY) {
            if(rank[rootX] < rank[rootY]) parent[rootX] = rootY;
            else if(rank[rootX] > rank[rootY]) parent[rootY] = rootX;
            else {
                parent[rootX] = rootY;
                rank[rootX]++;
            }
        }
    };
    
    function<bool(int, int)> IsSameUnion = [&](int x, int y) {
        return FindParent(x) == FindParent(y);
    };
    
    sort(costs.begin(), costs.end(), [&](vector<int>& vi1, vector<int>& vi2) {
        return vi1[2] < vi2[2];
    });
    
    for(auto& vi : costs) {
        int a = vi[0], b = vi[1], cost = vi[2];
        if(!IsSameUnion(a, b)) {
            SetUnion(a, b);
            answer += cost;
        }        
    }
    return answer;
}