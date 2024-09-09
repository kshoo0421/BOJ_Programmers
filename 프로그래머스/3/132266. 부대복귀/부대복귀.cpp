#include <bits/stdc++.h>
#define MAX 999999
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int dest) {
    vector<vector<bool>> able(n, vector<bool>(n, false));
    
    vector<vector<int>> link(n);
    vector<int> cost(n, MAX);
    vector<bool> visited(n, false);
    
    dest--;
    
    visited[dest] = true;
    for(auto& vi : roads) {
        vi[0]--, vi[1]--;
        able[vi[0]][vi[1]] = true;
        able[vi[1]][vi[0]] = true;
        link[vi[0]].emplace_back(vi[1]);
        link[vi[1]].emplace_back(vi[0]);
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(i == dest) cost[i] = 0;
        if(able[dest][i]) {
            cost[i] = 1;
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int tmp = q.front();
        q.pop();
        if(visited[tmp]) continue;
        visited[tmp] = true;
        for(int i : link[tmp]) {
            if(visited[i]) continue;
            if(cost[i] == MAX && able[i][tmp] == true) {
                cost[i] = cost[tmp] + 1;
                q.push(i);
            }
        }
    }
    
    vector<int> answer(sources.size());
    for(int i = 0; i < sources.size(); i++) {
        int tmp = cost[sources[i] - 1];
        if(tmp == MAX) answer[i] = -1;
        else answer[i] = tmp;
    }
    return answer;
}