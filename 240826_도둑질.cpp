#include <string>
#include <vector>
using namespace std;

int solution(vector<int> money) {
    int size = money.size();
    vector<int> steal0(size, 0), steal1(size, 0);
    steal0[0] = money[0], steal0[1] = money[0];
    steal1[1] = money[1];
    for(int i = 2; i < size; i++) {
        steal0[i] = max(steal0[i-1], steal0[i-2] + money[i]);
        steal1[i] = max(steal1[i-1], steal1[i-2] + money[i]);
    }
    return max(steal0[size-2], steal1[size-1]);    
}