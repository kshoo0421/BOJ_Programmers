#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int big = 0, small = 0;
    for(auto& vi : sizes) {
        big = max(big, max(vi[0], vi[1]));
        small = max(small, min(vi[0], vi[1]));
    }
    return big * small;
}