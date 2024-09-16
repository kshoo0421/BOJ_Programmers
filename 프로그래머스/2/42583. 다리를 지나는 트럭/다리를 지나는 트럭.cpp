#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int sum = 0, answer = 0;
    queue<int> bridge, trucks;
    for(int i = 0; i < bridge_length; i++) bridge.push(0);
    for(int i = 0; i < truck_weights.size(); i++) trucks.push(truck_weights[i]);

    while(1) {
        answer++;
        sum -= bridge.front();
        bridge.pop();
        
        if(sum + trucks.front() <= weight) {
            sum += trucks.front();
            bridge.push(trucks.front());
            trucks.pop();
            if(trucks.empty()) {
                answer += bridge_length;
                break;
            }
        }
        else bridge.push(0);        
    }     
    return answer;
}