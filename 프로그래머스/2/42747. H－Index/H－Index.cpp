#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int h = 0;
    sort(citations.rbegin(), citations.rend());    
    while(1) {
        if(citations[h] <= h) break;
        h++;
    }
    return h;
}