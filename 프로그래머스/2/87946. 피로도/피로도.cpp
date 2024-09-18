#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int size = dungeons.size(), answer = 0;
    vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));
    sort(dungeons.begin(), dungeons.end(), [](vector<int>& v1, vector<int>& v2) {
        int gap1 = v1[0] - v1[1];
        int gap2 = v2[0] - v2[1];
        if(gap1 != gap2) return gap1 > gap2;
        return v1[0] > v2[0];
    });
    
    for(int i = 0; i <= size; i++) dp[0][i] = k;
    
    for(int i = 1; i <= size; i++) {
        for(int j = 1; j <= size; j++) {
            for(int l = i-1; l < j; l++) {
                if(dp[i-1][l] >= dungeons[j-1][0]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][l] - dungeons[j-1][1]);
                    answer = i;
                }
            }
        }
    }
    return answer;
}