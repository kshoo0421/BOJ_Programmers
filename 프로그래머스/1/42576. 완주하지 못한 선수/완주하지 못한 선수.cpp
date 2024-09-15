#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> us;
    for(auto& s : completion) {
        if(us.find(s) == us.end()) us[s] = 0;
        else us[s]++;
    }
    for(auto& s : participant) {
        if(us.find(s) == us.end()) return s;
        else {
            if(us[s] < 0) return s;
            else us[s]--;
        }
        
    }
    return "error";
}