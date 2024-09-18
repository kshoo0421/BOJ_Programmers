#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    int size = number.size();
    string answer = "";
    vector<int> idxs;
    for(int i = k; i < size; i++) {
        answer += number[i];
        idxs.emplace_back(i);
    }
    
    for(int i = idxs[0]; i >= 0; i--) {
        if(number[i] >= answer[0]) {
            answer[0] = number[i];
            idxs[0] = i;
        }
    }
    
    for(int i = 1; i < idxs.size(); i++) {
        for(int j = idxs[i]; j > idxs[i - 1]; j--) {
            if(number[j] >= answer[i]) {
                answer[i] = number[j];
                idxs[i] = j;
            }
        }
    }
    return answer;
}