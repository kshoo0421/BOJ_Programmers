#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    int s1[5] = {1, 2, 3, 4, 5};
    int s2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int s3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> correct(3, 0);

    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == s1[i % 5]) correct[0]++;
        if(answers[i] == s2[i % 8]) correct[1]++;
        if(answers[i] == s3[i % 10]) correct[2]++;
    }
    
    int top = *max_element(correct.begin(), correct.end());

    vector<int> answer;
    for(int i = 0; i < 3; i++) {
        if(top == correct[i]) answer.emplace_back(i + 1);
    }
    return answer;
}