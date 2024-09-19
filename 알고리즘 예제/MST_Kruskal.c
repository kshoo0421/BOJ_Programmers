#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e;
    // (비용, 정점1, 정점2)
    tuple<int, int, int> edge[100005];

    sort(edge, edge + e);
    int cnt = 0;
    for(int i = 0; i < e; i++) {
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue; // union find
        cout << cost << ' ' << a << ' ' << b << '\n';
        cnt++;
        if(cnt == v-1) break;
    }
}