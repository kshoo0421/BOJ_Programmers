#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> numbers) {
    vector<string> vs;
    for(int i : numbers) vs.emplace_back(to_string(i));    

    sort(vs.begin(), vs.end(), [](string& s1, string& s2) {
        return (s1 + s2) > (s2 + s1);    
    });
    
    string answer = "";
    for(auto& s : vs) answer += s;
    if(answer[0] == '0') answer = "0";
    return answer;
}