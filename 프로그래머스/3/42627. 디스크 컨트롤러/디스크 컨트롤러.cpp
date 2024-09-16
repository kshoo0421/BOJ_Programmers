#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0, time = 0, idx, cur, size = jobs.size();
    
    sort(jobs.begin(), jobs.end(), [](vector<int>& vi1, vector<int>& vi2) {
        if(vi1[0] != vi2[0]) return vi1[0] < vi2[0];
        return vi1[1] < vi2[1];
    });
    
    while(!jobs.empty()) {
        idx = -1, cur = jobs[0][1] + 1;
        for(int i = 0; i < jobs.size(); i++) {
            if(time < jobs[i][0]) break;
            if(jobs[i][1] < cur) {
                idx = i;
                cur = jobs[i][1];
            }
        }
        if(idx == -1) time++;
        else {
            answer += (time + jobs[idx][1] - jobs[idx][0]);
            time += jobs[idx][1];
            jobs.erase(jobs.begin() + idx);
        }
    }
    return answer / size;
}