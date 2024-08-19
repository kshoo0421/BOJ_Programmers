#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, aIdx = 0, bIdx = 0;
    int aSize = A.size();
    int bSize = B.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    while(aIdx < aSize && bIdx < bSize) {
        if(A[aIdx] < B[bIdx]) {
            answer++;
            aIdx++;
            bIdx++;
        }
        else bIdx++;
    }
    return answer;
}