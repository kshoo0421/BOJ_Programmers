#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    int rank = 0;
    vector<int> sorted = priorities;
    sort(sorted.rbegin(), sorted.rend());
    
    while(1) {
        for(int i = 0; i < priorities.size(); i++) {
            if(sorted[rank] == priorities[i]) {
                rank++;
                priorities[i] = -1;
                if(i == location) return rank;
            }
        }
    }
    return -1;
}