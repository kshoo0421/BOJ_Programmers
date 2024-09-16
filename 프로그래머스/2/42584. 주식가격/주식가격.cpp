#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size, 0);
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            answer[i]++;
            if(prices[i] > prices[j]) break;
        }
    }
    return answer;
}