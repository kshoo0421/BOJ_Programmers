#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> us(nums.begin(), nums.end());
    return min(us.size() , nums.size() / 2);
}