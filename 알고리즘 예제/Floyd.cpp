#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main() 
{
    int V, E;
    cin >> V >> E;  // V는 정점의 개수, E는 간선의 개수
    
    // 거리 배열을 INF로 초기화 (자기 자신으로의 거리는 0)
    vector<vector<int>> dist(V, vector<int>(V, INF));
    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }

    // 간선 입력 받기
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // u에서 v로 가는 가중치 w
        dist[u][v] = min(dist[u][v], w);
    }

    function<void()> Floyd = [&]() {
        for (int k = 0; k < V; k++) {  // 중간 노드
            for (int i = 0; i < V; i++) {  // 출발 노드
                for (int j = 0; j < V; j++) {  // 도착 노드
                    // i에서 j로 가는 최단 경로를 i -> k -> j를 거쳐서 갈 때 더 짧은지 확인
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    };

    // 플로이드-워셜 알고리즘 수행
    Floyd();

    // 결과 출력
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } 
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}