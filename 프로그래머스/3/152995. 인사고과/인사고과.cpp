#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define S1 first
#define S2 second

struct Man {
    int idx, score1, score2, total;
    bool noMoney;
};

int solution(vector<vector<int>> scores) {
    int answer = 0, size = scores.size();
    vector<Man> mans(size);
    pair<int, int> best;
    
    for(int i = 0; i < size; i++) {
        mans[i].idx = i;
        mans[i].score1 = scores[i][0];
        mans[i].score2 = scores[i][1];
        mans[i].total = scores[i][0] + scores[i][1];
        mans[i].noMoney = false;
    }
    
    sort(mans.begin(), mans.end(), [](Man& m1, Man& m2){
        return m1.score1 > m2.score1;
    });
    
    best = {mans[0].score1, mans[0].score2};
    for(int i = 1; i < size; i++) {
        if(best.S2 > mans[i].score2) mans[i].noMoney = true;
    }
    
    int idx = 0;
    while(idx < size) {
        idx++;
        if(best.S2 >= mans[idx].score2) continue;
        best = {mans[idx].score1, mans[idx].score2};
        for(int i = 0; i < size; i++) {
            if(mans[i].noMoney) continue;
            if(best.S1 > mans[i].score1 && best.S2 > mans[i].score2) {
                mans[i].noMoney = true;                
            }
        }
    }
    
    sort(mans.begin(), mans.end(), [](Man& m1, Man& m2){
        if(m1.noMoney && m2.noMoney) return m1.total > m2.total;
        if(m1.noMoney) return false;
        if(m2.noMoney) return true;
        
        if(m1.total == m2.total) return m1.idx < m2.idx;
        return m1.total > m2.total;
    });
    
    for(int i = 0; i < size; i++) {
        if(mans[i].idx == 0) {
            if(mans[i].noMoney) return -1;
            return i + 1;
        }
    }
}