#include <vector>
#include <queue>
using namespace std;

#define Y first
#define X second

int dy[] = {1, 0};
int dx[] = {0, 1};

int MOD = 20170805;

vector<vector<int>> fromUp, fromLeft;
vector<vector<bool>> visited;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    pair<int, int> cur, next;
    
    visited.assign(m, vector<bool>(n, false));
    fromUp.assign(m, vector<int>(n, 0));
    fromLeft.assign(m, vector<int>(n, 0));
    
    fromUp[1][0] = 1;
    fromLeft[0][1] = 1;
    
    queue<pair<int, int>> q;
    q.push({1, 0});
    q.push({0, 1});    
    
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        if(visited[cur.Y][cur.X]) continue;
        visited[cur.Y][cur.X] = true;
        
        switch(city_map[cur.Y][cur.X]) {
            case 0:
                for(int i = 0; i < 2; i++) {
                    next.X = cur.X + dx[i];
                    next.Y = cur.Y + dy[i];
                    if(next.X >= n || next.Y >= m) continue;
                    q.push({next.Y, next.X});
                    if(i == 0) {
                        fromUp[next.Y][next.X] += fromUp[cur.Y][cur.X];
                        fromUp[next.Y][next.X] += fromLeft[cur.Y][cur.X];
                        fromUp[next.Y][next.X] %= MOD;
                    }
                    else {
                        fromLeft[next.Y][next.X] += fromUp[cur.Y][cur.X];
                        fromLeft[next.Y][next.X] += fromLeft[cur.Y][cur.X];
                        fromLeft[next.Y][next.X] %= MOD;
                    }
                }
                break;
            case 1:
                fromLeft[cur.Y][cur.X] = 0;
                fromUp[cur.Y][cur.X] = 0;
                break;
            case 2:
                for(int i = 0; i < 2; i++) {
                    next.X = cur.X + dx[i];
                    next.Y = cur.Y + dy[i];
                    if(next.X >= n || next.Y >= m) continue;
                    q.push({next.Y, next.X});
                    if(i == 0) {
                        fromUp[next.Y][next.X] += fromUp[cur.Y][cur.X];
                        fromUp[next.Y][next.X] %= MOD;
                    }
                    else {
                        fromLeft[next.Y][next.X] += fromLeft[cur.Y][cur.X];
                        fromLeft[next.Y][next.X] %= MOD;
                    }
                }
                break;
        }
    }    
    return (fromUp[m-1][n-1] + fromLeft[m-1][n-1]) % MOD;
}