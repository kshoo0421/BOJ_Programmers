#include <bits/stdc++.h>
using namespace std;

int solution(string word) {        
    int answer = 1, idx = 0;
    vector<int> a = {1, 0, 0, 0, 0};    
    vector<char> c = {'\0', 'A', 'E', 'I', 'O', 'U'};

    function<void()> NextWord = [&]() -> void {
        answer++;
        if(idx < 4) {
            idx++;
            a[idx]++;
        }
        else {
            a[idx]++;
            while(a[idx] > 5) {
                a[idx] = 0;
                idx--;
                a[idx]++;
            }
        }
    };
    
    function<string()> GetStr = [&]() -> string {
        string result = "";
        for(int i = 0; i < 5; i++) {
            if(a[i] == 0) break;
            result += c[a[i]];
        }
        return result;
    };
    
    while(GetStr() != word) {
        NextWord();
        if(answer >= 20000) break;
    }   

    return answer;
}