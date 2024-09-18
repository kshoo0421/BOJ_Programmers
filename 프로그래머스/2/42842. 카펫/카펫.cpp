#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int sum = brown + yellow;
    vector<int> ans(2, 3);

    while(1) {
        if(sum % ans[0] == 0) {
            ans[1] = sum / ans[0];
            if((ans[0] - 2) * (ans[1] - 2) == yellow) {
                if(ans[0] < ans[1]) swap(ans[0], ans[1]);
                return ans;
            }
        }
        ans[0]++;
    }    
    return ans;
}