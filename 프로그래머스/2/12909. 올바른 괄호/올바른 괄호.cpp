#include <bits/stdc++.h>
using namespace std;

bool solution(string s) {
    stack<bool> stk;
    for(char& c : s) {
        if(c == '(') stk.push(true);
        else {
            if(stk.empty()) return false;
            else stk.pop();
        }
    }
    return stk.empty();
}