#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {    
    int rSize = rc.size();
    int idx1 = 0, idx2 = rSize - 1;
    deque<int> l, r;
    deque<deque<int>> c;
    
    for(int i = 0; i < rSize; i++) {
        l.push_back(rc[i].front());

        deque<int> tmp;
        copy(rc[i].begin() + 1, rc[i].end() - 1, back_inserter(tmp));
        c.push_back(tmp);

        r.push_back(rc[i].back());
    }

    for(auto& s : operations) {
        if(s == "ShiftRow") {
            l.push_front(l.back());
            l.pop_back();
            
            r.push_front(r.back());
            r.pop_back();
            
            idx1--, idx2--;
            if(idx1 < 0) idx1 += rSize;
            if(idx2 < 0) idx2 += rSize;
        }
        else {
            deque<int>& cUp = c[idx1];
            deque<int>& cDown = c[idx2];            
            
            cUp.push_front(l.front());
            r.push_front(cUp.back());
            cDown.push_back(r.back());
            l.push_back(cDown.front());
            
            l.pop_front();
            cUp.pop_back();
            r.pop_back();
            cDown.pop_front();
        }
    }
    
    for(int i = 0; i < idx1; i++) {
        c.push_back(c.front());
        c.pop_front();
    }
    
    for(int i = 0; i < rSize; i++) {
        c[i].push_front(l[i]);
        c[i].push_back(r[i]);
        rc[i].assign(c[i].begin(), c[i].end());
    }
    return rc;
}