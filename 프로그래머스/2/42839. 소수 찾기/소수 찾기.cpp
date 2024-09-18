#include <bits/stdc++.h>
using namespace std;

int solution(string numbers) {
    sort(numbers.rbegin(), numbers.rend());
    int maximum = stoi(numbers);
    vector<bool> isPrime(maximum, true);
    isPrime[0] = false, isPrime[1] = false;
    for(int i = 2; i <= maximum; i++) {
        if(isPrime[i] == false) continue;
        for(int j = i * 2; j <= maximum; j += i) {
            isPrime[j] = false;
        }
    }
    
    unordered_set<int> answer;
    reverse(numbers.begin(), numbers.end());
    do {
        for(int i = 1; i <= numbers.size(); i++) {
            string s = numbers.substr(0, i);
            int tmp = stoi(s);
            if(isPrime[tmp]) answer.insert(tmp);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    return answer.size();
}