#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    vector<bool> linked(n + 1, false);
    vector<vector<int>> Nodes(n + 1);
    
    for(auto& v : wires) {
        Nodes[v[0]].emplace_back(v[1]);
        Nodes[v[1]].emplace_back(v[0]);
    }
    
    stack<pair<int, int>> stk;
    for(auto& v : wires) {
        linked.assign(n + 1, false);
        linked[1] = true;
        
        for(int& i : Nodes[1]) {
            if(v[0] == 1 && v[1] == i) continue;
            stk.push({1, i});
        }
        
        while(!stk.empty()) {
            pair<int, int> tmp = stk.top();
            stk.pop();
            
            if(linked[tmp.S]) continue;
            if(tmp.F == v[0] && tmp.S == v[1]) continue;
            if(tmp.F == v[1] && tmp.S == v[0]) continue;
            
            linked[tmp.S] = true;
            for(const int& i : Nodes[tmp.S]) {
                if(linked[i]) continue;
                stk.push({tmp.S, i});
            }
        }
        
        int g1 = 0, g2 = 0;
        for(int i = 1; i <= n; i++) {
            if(linked[i]) g1++;
            else g2++;
        }
        answer = min(answer, abs(g1 - g2));
    }
    return answer;
}