#include <bits/stdc++.h>
using namespace std;


int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> visited(dungeons.size(), false);
    
    function<void(int, int)> dfs = [&](int k, int count) -> void {
        answer = max(answer, count);
        for (int i = 0; i < dungeons.size(); ++i) {
            if (!visited[i] && k >= dungeons[i][0]) {
                visited[i] = true;
                dfs(k - dungeons[i][1], count + 1);  
                visited[i] = false;  
            }
        }    
    };
    dfs(k, 0);
    return answer;
}
