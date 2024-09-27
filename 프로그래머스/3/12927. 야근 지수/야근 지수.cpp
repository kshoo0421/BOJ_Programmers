#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> works) {
    int size = works.size();
    long long answer = 0, sum = 0;
    vector<int> result(size, 0);
    sort(works.begin(), works.end());
    
    for(int i : works) sum += i;
    sum -= n;
    if(sum <= 0) return 0;
    
    while(1) {
        for(int i = 0; i < size; i++) {
            if(works[i] == result[i]) continue;
            result[i]++;
            sum--;
            if(sum == 0) break;
        }
        if(sum <= 0) break;
    }
    for(int i : result) answer += (long long)(i * i);
    return answer;
}