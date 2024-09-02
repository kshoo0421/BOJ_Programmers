#include <iostream>
#include <vector>
#include <algorithm>
#define START first
#define END second
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, range = 2 * w + 1;
    vector<pair<int, int>> possible;
    
    sort(stations.begin(), stations.end());
    possible.push_back({0, 0});
    for(int i : stations) {
        possible.push_back({i - w, i + w});
    }
    
    for(int i = 1; i < possible.size(); i++) {
        while(possible[i - 1].END + 1 < possible[i].START) {
            possible[i].START -= range;
            answer++;
        }        
    }
    while(possible.back().END < n) {
        possible.back().END += range;
        answer++;
    }
        
    return answer;
}