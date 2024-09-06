#include <string>
#include <vector>
using namespace std;

int solution(vector<int> a) {
    int answer = 0, n = a.size();
    int lMin = a[0], rMin = a[n - 1];
    vector<int> lMins(n), rMins(n);
    for(int i = 0; i < n; i++) {
        lMin = min(lMin, a[i]);
        rMin = min(rMin, a[n - i - 1]);

        lMins[i] = lMin;
        rMins[n - i - 1] = rMin;
    }
    
    for(int i = 0; i < n; i++) {
        if(i == 0 || i == n - 1) answer++;
        else {
            if(lMins[i - 1] >= a[i] || rMins[i + 1] >= a[i]) answer++;
        }
    }
    return answer;
}