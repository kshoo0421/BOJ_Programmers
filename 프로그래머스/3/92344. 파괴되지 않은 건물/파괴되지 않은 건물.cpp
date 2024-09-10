#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int R = board.size(), C = board[0].size();
    
    vector<vector<int>> memo(R + 1, vector<int>(C + 1, 0));
    for(auto& vi : skill) {
        memo[vi[1]][vi[2]] += (vi[0] == 1 ? -1 : 1) * vi[5];
        memo[vi[1]][vi[4] + 1] -= (vi[0] == 1 ? -1 : 1) * vi[5];
        memo[vi[3] + 1][vi[2]] -= (vi[0] == 1 ? -1 : 1) * vi[5];
        memo[vi[3] + 1][vi[4] + 1] += (vi[0] == 1 ? -1 : 1) * vi[5];
    }

    for(int i = 0; i < R; i++) {
        for(int j = 1; j < C; j++) {
            memo[i][j] += memo[i][j - 1];
        }
    }
 
    for(int j = 0; j < C; j++) {
       for(int i = 1; i < R; i++) {
            memo[i][j] += memo[i - 1][j];
       }
    }
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(memo[i][j] + board[i][j] > 0) answer++;
        }
    }
    return answer;
}