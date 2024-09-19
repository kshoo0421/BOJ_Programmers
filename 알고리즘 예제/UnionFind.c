#include <bits/stdc++.h>
using namespace std;

int solution(int n) // n : 노드의 수
{
    vector<int> parent(n + 1, 0);
    vector<int> rank(n + 1, 0);


    // 자기 자신을 부모로 설정
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    function<int(int)> FindParent = [&](int x) {
        if(parent[x] == x) return x;
        return parent[x] = FindParent(parent[x]); 
    };

    function<void(int, int)> SetUnion = [&](int x, int y) {
        int rootX = FindParent(x);
        int rootY = FindParent(y);

        if(rootX != rootY) {
            // 크기나 랭크에 기반해 더 작은 트리를 큰 트리에 붙이는 방식
            if(rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            else if(rank[rootX] < rank[rootY]) {
                parent[rootY] = rootX;
            }
            else {
                parent[rootY] = rootX;
                rank[rootX]++; // 랭크가 같은 경우 루트 변경 후 랭크 증가
            }
        }
    };


    // 그래프의 간선들
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {2, 3}, {4, 5}};

    for(auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;

        if(FindParent(u) == FindParent(v)) {
            cout << "동일 부모\n";
        }
        else {
            SetUnion(u, v);
            cout << "합치기 완료\n";
        }
    }
}