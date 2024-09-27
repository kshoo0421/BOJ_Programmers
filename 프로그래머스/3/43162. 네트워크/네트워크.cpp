#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& computers, int n) {
    int tmp;
    stack<int> stk;
    stk.push(n);
    computers[n][n] = 0;
    while(!stk.empty()) {
        tmp = stk.top();
        stk.pop();
        for(int i = 0; i < computers.size(); i++) {
            if(computers[tmp][i] == 1) {  
                stk.push(i); 
                computers[tmp][i] = 0;
                computers[i][tmp] = 0;
            }
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0, size = computers.size();
    
    for(int i = 0; i < size; i++) {
        if(computers[i][i] == 1) {
            dfs(computers, i);
            answer++;
        }        
    }
    return answer;
}