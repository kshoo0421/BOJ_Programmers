#include <bits/stdc++.h>
using namespace std;
#define LL long long

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());

    LL l = (LL)times.front();
    LL r = (LL)times.back() * n;
    LL answer = r;
    while(l <= r){
        long long m = (r + l) / 2;
        long long cur = 0;

        for(int& i : times) cur += m / (LL)i;

        if(cur >= n){
            r = m - 1;
            if(m <= answer) answer = m;
        }
        else l = m + 1;
    }
    return answer;
}