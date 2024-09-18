#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    vector<bool> bReserve(n+2, false), bLost(n+2, false);

    for(int i : reserve) bReserve[i] = true;    
    for(int i : lost) bLost[i] = true; 
    
    for(int i = 1; i <= n; i++) {
        if(bLost[i] && bReserve[i]) {
            bLost[i] = false;
            bReserve[i] = false;
            answer++;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(bLost[i]) {
            if(bReserve[i - 1] || bReserve[i + 1]) {
                if(bReserve[i - 1] == true) bReserve[i - 1] = false;
                else bReserve[i + 1] = false;
                bLost[i] = true;
                answer++;                
            }
        }
    }
    return answer;
}