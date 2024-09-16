#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, tmp;
    priority_queue<int, vector<int>, greater<int>> pqi(scoville.begin(), scoville.end());
    while(pqi.top() < K) {
        if(pqi.size() < 2) return -1;
        
        answer++;
        tmp = pqi.top();
        pqi.pop();
        
        tmp += (pqi.top() * 2);
        pqi.pop();
        
        pqi.push(tmp);
        
    }
    return answer;
}