#include <string>
#include <vector>
#include <stack>
using namespace std;

int answer = 0;
int total;

void backTracking(int idx, stack<bool> stk) {
    if(idx == total) {
        answer++;
        return;
    }
    if(!stk.empty()) {
        stk.push(true);
        backTracking(idx + 1, stk);    
        stk.pop();
        stk.pop();
        backTracking(idx, stk);    
    }
    else {
        stk.push(true);
        backTracking(idx + 1, stk);    
    }
    return;    
}

int solution(int n) {
    total = n;
    stack<bool> stk;
    backTracking(0, stk);
    return answer;
}