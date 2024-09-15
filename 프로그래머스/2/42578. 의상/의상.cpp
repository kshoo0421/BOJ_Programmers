#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    for(auto& vs : clothes) {
        if(m.find(vs[1]) == m.end()) m[vs[1]] = 2;
        else m[vs[1]]++;
    }
    for(auto& it : m) {
        answer *= it.second;
    }
    return answer - 1;
}