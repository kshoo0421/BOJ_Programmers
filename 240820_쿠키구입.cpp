#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0, lSum, rSum, N = cookie.size();
    
    vector<int> sums(N + 1, 0);
    for(int i = 0; i < N; i++) {
        sums[i + 1] = sums[i] + cookie[i];
    }
    
    for(int m = 0; m < N - 1; m++) {
        for(int l = 0; l <= m; l++) {
            lSum = sums[m + 1] - sums[l];
            if(lSum <= answer) break;
            
            for(int r = N - 1; r > m; r--) {
                rSum = sums[r + 1] - sums[m + 1];
                if(rSum <= lSum) break;                
            }
            if(rSum == lSum) answer = lSum;
        }
    }
    return answer;
}