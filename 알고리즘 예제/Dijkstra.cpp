#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> graph(V + 1);
    vector<int> dist(V + 1, INT_MAX);

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    function<void(int)> Dijkstra = [&](int start) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
            greater<pair<int, int>>> pq;
        dist[start] = 0;
        pq.push({0, start});

        while(!pq.empty()) {
            int curDist, curNode;
            tie(curDist, curNode) = pq.top();
            pq.pop();
            if(dist[curNode] < curDist) continue;

            for(auto pii : graph[curNode]) {
                int nxtNode, weight;
                tie(nxtNode, weight) = pii;

                if(dist[nxtNode] > dist[curNode] + weight) {
                    dist[nxtNode] = dist[curNode] + weight;
                    pq.push({dist[nxtNode], nxtNode});
                }
            }
        }
    };

    int start;
    cin >> start;
    Dijkstra(start);

    for(int i = 1; i <= V; i++) {
        if(dist[i] == INT_MAX) cout << "INF\n"; 
        else cout << dist[i] << "\n";
    }
}