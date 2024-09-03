#include <string>
#include <vector>
#include <algorithm>
#define VAL first
#define IDX second
using namespace std;

int solution(vector<int> food_times, long long k) {
    int lastMin = 0;
    vector<pair<int, int>> left;
    for(int i = 0; i < food_times.size(); i++) 
        left.push_back({food_times[i], i + 1});
    
    sort(left.rbegin(), left.rend());
    
    while(1) {
        while(left.back().VAL == lastMin) left.pop_back();
        
        int size = left.size();
        if(size == 0) return -1;
        
        int tmp = k / size;
        int minVal = left.back().VAL - lastMin;
        
        if(tmp >= minVal) {
            k -= (minVal * size);
            lastMin = left.back().VAL;
        }
        else {
            k -= (long long)((long long)tmp * size);
            sort(left.begin(), left.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
                return p1.IDX < p2.IDX;
            });
            return left[k].IDX;
        }
    }
    return -1;
}