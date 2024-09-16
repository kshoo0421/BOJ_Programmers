#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer, tmp;
    for(auto& vi : commands) {
        tmp.assign(array.begin() + vi[0] - 1, array.begin() + vi[1]);
        sort(tmp.begin(), tmp.end());
        answer.emplace_back(tmp[vi[2] - 1]);
    }    
    return answer;
}