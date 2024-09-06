#include <string>
#include <vector>
#include <stack>
#define X first
#define Y second

#define S first // START
#define E second // END
using namespace std;

int dx[] = {0, 0, 1, -1}; // 역순 -> 방향 반대
int dy[] = {1, -1, 0, 0}; // 역순 -> 방향 반대

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    pair<int, int> xRange = { x, x }, yRange = { y, y }, tmp;
    
    stack<pair<int, int>> stk; // 스택에 쌓고 pop하며 역순으로 진행
    for(auto& query : queries) {
        tmp.X = dx[query[0]] * query[1]; // 한 번에 가는 X 범위
        tmp.Y = dy[query[0]] * query[1]; // 한 번에 가는 Y 범위
        stk.push(tmp);
    }
    
    while(!stk.empty()) { 
        tmp = stk.top();
        stk.pop();
        if(tmp.X != 0) { // x 값이 변경되는 경우
            if(tmp.X > 0) { // x 값이 양수로 변경
                if(xRange.S == 0) xRange.S = 0; // 시작 지점이 0이면 0으로 고정
                else xRange.S += tmp.X; // 아니면 그 값만큼 더하기
                xRange.E += tmp.X; // 끝 값은 그대로 더하기
            }
            else {
                if(xRange.E == n - 1) xRange.E = n - 1; // 끝 지점이 n-1이면 n-1로 고정
                else xRange.E += tmp.X; // 아니라면 그 값 그대로 빼주기
                xRange.S += tmp.X; // 시작 값은 그대로 더하기
            }
            if(xRange.E < 0 || xRange.S >= n) return 0; // 불가능한 범위

            if(xRange.S < 0) xRange.S = 0; // S가 0보다 작으면 0으로 조정
            if(xRange.E >= n) xRange.E = n - 1; // E가 n보다 크거나 같다면 n-1로 조정
        }
        else { // Y도 마찬가지
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
    long long xDist = abs(xRange.E - xRange.S) + 1; // 가능한 x 범위
    long long yDist = abs(yRange.E - yRange.S) + 1; // 가능한 y 범위
    
    return xDist * yDist;
}