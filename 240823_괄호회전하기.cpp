#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0, size = s.size();
    s = s + s;
    for(int i = 0; i < size; i++) {
        stack<char> stk;
        for(int j = i; j < i + size; j++) {
            if(s[j] == '(' || s[j] == '[' || s[j] == '{') {
                stk.push(s[j]);
            }
            else {
                if(stk.empty()) {
                    stk.push('e'); // error
                    break;
                }
                if(stk.top() == '(' && s[j] == ')') {
                    stk.pop();
                }
                else if(stk.top() == '[' && s[j] == ']') {
                    stk.pop();
                }
                else if(stk.top() == '{' && s[j] == '}') {
                    stk.pop();
                }
                else break;
            }
        }
        if(stk.empty()) answer++;
    }
    return answer;
}