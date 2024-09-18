#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int size = name.size();
    vector<int> move(size, 0);
    for(int i = 0; i < size; i++) {
        move[i] = min(name[i] - 'A', 'Z' - name[i] + 1);
    }

    int answer = size * 2, l, r;    
    for(l = 0; l < size; l++) {
        r = l + 1;
        while(r < size) {
            if(move[r] == 0) r++;
            else break;
        }
        r = size - r;
        answer = min(answer, (l + r) + min(l, r));
    }
    for(int i : move) answer += i;
    return answer;
}