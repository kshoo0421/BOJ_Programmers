#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(vector<int> v1, vector<int> v2)
{
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1, curCamera;
    sort(routes.begin(), routes.end(), cmp);
    curCamera = routes[0][1];
    
    for(auto v : routes)
    {
        if(v[0] <= curCamera) continue;
        answer++;
        curCamera = v[1];
    }
    return answer;
}