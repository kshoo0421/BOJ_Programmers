#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int day, maxDay = 0;
    vector<int> answer;
    for(int i = 0; i < progresses.size(); i++) {
        day = ((99 - progresses[i]) / speeds[i]) + 1;
        if(answer.empty() || maxDay < day) {
            answer.emplace_back(1);
            maxDay = day;
        }
        else answer.back()++;
    }
    return answer;
}