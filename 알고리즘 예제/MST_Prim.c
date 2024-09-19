#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main() {
    int v, e;
    // (비용, 정점 번호)
    vector<pair<int, int>> adj[10005];
    //chk[i] : i번째 정점이 최소 신장 트리에 속해있는가?
    bool chk[10005];
    int cnt = 0;
    // tuple<int, int, int> : (비용, 정점1, 정점2)
    priority_queue< tuple<int, int, int>,
                    vector<tuple<int, int, int>>,
                    greater<tuple<int, int, int>>> pq;
    chk[1] = 1;
    for(auto nxt : adj[1])
        pq.push({nxt.X, 1, nxt.Y});
    while(cnt < v - 1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if(chk[b]) continue;
        cout << cost << ' ' << a << ' ' << b << '\n';
        chk[b] = 1;
        cnt++;
        for(auto nxt : adj[b]) {
            if(!chk[nxt.Y])
                pq.push({nxt.X, b, nxt.Y});
        } 
    }
}

