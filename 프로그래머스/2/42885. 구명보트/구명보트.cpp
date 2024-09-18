#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, l = 0, r = people.size() - 1;
    sort(people.begin(), people.end());
    while(l <= r) {
        if(l == r) l++;
        else if(people[l] + people[r] <= limit) {
            l++;
            r--;
        }
        else r--;
        answer++;
    }
    return answer;
}