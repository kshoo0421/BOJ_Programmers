#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<int>> bridge;
    
    sort(costs.begin(), costs.end(), [&](vector<int>& v1, vector<int>& v2) {
        if(v1[2] != v2[2]) return v1[2] < v2[2];
        return v1[0] < v2[0];
    });
    
    function<bool(int, int)> isConnected = [&](int i1, int i2) -> bool {
        vector<bool> island(n, false);
        if(bridge.size() != 0) island[i1] = true;    
        for(int i = 0; i < 5; i++) {
            for(auto& v : bridge) {
                if(island[v[0]] != island[v[1]]) {
                    island[v[0]] = true;
                    island[v[1]] = true;
                }
            }
        }
        return island[i2];
    };
    
    for(auto& v : costs) {
        if(isConnected(v[0], v[1])) continue;
        answer += v[2];
        bridge.emplace_back(vector<int>({v[0], v[1]}));
        if(bridge.size() == n - 1) break;
    }
    return answer;
}