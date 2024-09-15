#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer(1, arr.front());
    for(int& i : arr) {
        if(i != answer.back()) answer.emplace_back(i);
    }
    return answer;
}