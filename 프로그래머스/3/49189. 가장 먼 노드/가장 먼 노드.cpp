#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int length = -1;
    vector<int> link;
} Node;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, tmp;
    vector<Node> Nodes(n + 1);
    Nodes[1].length = 0;
    for(auto v : edge) {
        Nodes[v[0]].link.emplace_back(v[1]);
        Nodes[v[1]].link.emplace_back(v[0]);
    }
    
    function<bool()> isEnd = [&]() {
        for(auto n : Nodes) if(n.length == -1) return false;
        return true;
    };    
    
    for(int i = 1; i < n; i++) {
        for(auto& N : Nodes) {
            if(N.length != -1) continue;
            for(int j : N.link) {
                tmp = Nodes[j].length;
                if(tmp != -1 && tmp != i) N.length = i;
            }
        }
        if(isEnd()) break;
    }
    
    sort(Nodes.begin(), Nodes.end(), [](Node n1, Node n2) {
        return n1.length > n2.length;
    });
    tmp = Nodes[0].length;
    for(auto n : Nodes) {
        if(tmp == n.length) answer++;
        else break;
    }
    return answer;
}