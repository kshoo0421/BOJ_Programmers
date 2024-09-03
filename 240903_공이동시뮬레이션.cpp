#include <string>
#include <vector>
#include <stack>
#define X first
#define Y second

#define S first
#define E second
using namespace std;

int dx[] = {0, 0, 1, -1}; // 역순 -> 방향 반대
int dy[] = {1, -1, 0, 0}; // 역순 -> 방향 반대

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    int nx, ny;
    pair<int, int> tmp;
    pair<int, int> xRange = { x, x };
    pair<int, int> yRange = { y, y };
    
    stack<pair<int, int>> stk;
    for(auto& query : queries) {
        tmp.X = dx[query[0]] * query[1];
        tmp.Y = dy[query[0]] * query[1];
        stk.push(tmp);
    }
    
    while(!stk.empty()) {
        tmp = stk.top();
        stk.pop();
        if(tmp.X != 0) {
            if(tmp.X > 0) {
                if(xRange.S == 0) xRange.S = 0;
                else xRange.S += tmp.X;
                xRange.E += tmp.X;            
            }
            else {
                if(xRange.E == n - 1) xRange.E = n - 1;
                else xRange.E += tmp.X;
                xRange.S += tmp.X;                            
            }
            if(xRange.E < 0 || xRange.S >= n) return 0;

            if(xRange.S < 0) xRange.S = 0;
            if(xRange.E >= n) xRange.E = n - 1;
        }
        else { // Y
            if(tmp.Y > 0) {
                if(yRange.S == 0) yRange.S = 0;
                else yRange.S += tmp.Y;
                yRange.E += tmp.Y;            
            }
            else {
                if(yRange.E == m - 1) yRange.E = m - 1;
                else yRange.E += tmp.Y;
                yRange.S += tmp.Y;                            
            }
            if(yRange.E < 0 || yRange.S >= m) return 0;

            if(yRange.S < 0) yRange.S = 0;
            if(yRange.E >= m) yRange.E = m - 1;
        }
    }
    return ((long long)abs(xRange.E - xRange.S) + 1) * ((long long)abs(yRange.E - yRange.S) + 1);
}