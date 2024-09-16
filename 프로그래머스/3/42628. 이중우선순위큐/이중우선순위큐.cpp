#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<char> command;
    vector<int> nums;
    for(auto& s : operations) {
        command.emplace_back(s[0]);
        nums.emplace_back(stoi(s.substr(2, s.size() - 2)));
    }
    
    deque<int> dq;
    
    for(int i = 0; i < nums.size(); i++) {
        if(command[i] == 'D') {
            if(nums[i] == 1) {
                if(!dq.empty()) dq.pop_front();
            }
            else {
                if(!dq.empty()) dq.pop_back();                
            }
        }
        else {
            dq.push_back(nums[i]);
            sort(dq.rbegin(), dq.rend());
        }
    }
    
    vector<int> answer(2, 0);
    if(!dq.empty()) {
        answer[0] = dq.front();
        answer[1] = dq.back();        
    }
    return answer;
}