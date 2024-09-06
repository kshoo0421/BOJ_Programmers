#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    rocks.emplace_back(distance);

    int size = rocks.size();
    sort(rocks.begin(), rocks.end()); 
    vector<int> dists(size);
    dists[0] = rocks[0];
    for(int i = 1; i < size; i++) {
        dists[i] = rocks[i] - rocks[i - 1];
    }    
    
    int answer = 0, l = 1, r = distance;
    
    while(l <= r) {
        int m = (l + r) / 2;
        int cnt = 0, sum = 0;
        for(int i = 0; i < size; i++) {
            sum += dists[i];
            if (sum < m) cnt++;
            else sum = 0;   
        }
        
        if(cnt > n) r = m - 1;
        else {
            answer = m;
            l = m + 1;
        }
    }
    return answer;
}