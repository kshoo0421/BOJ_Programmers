#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> pb) {
    unordered_set<string> us(pb.begin(), pb.end());
    for(auto& s : pb) {
        string tmp = "";
        for(int i = 0; i < s.size() - 1; i++) {
            tmp += s[i];
            if(us.find(tmp) != us.end()) return false;
        }
    }
    return true;    
}