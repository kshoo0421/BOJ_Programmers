#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(vector<string> words) {
    int answer = 0;
    unordered_map<string, string> search;
    sort(words.begin(), words.end());
    for(auto s : words) {
        string word = "";
        for(char c : s) {
            word += c;
            if(search.find(word) == search.end()) {
                search[word] = s;
                break;
            }
            else {
                if(search[word] != "-" && search[word] != word) {
                        string tmp = word;
                        tmp += search[word][word.size()];
                        search[tmp] = search[word];
                        search[word] = "-";                        
                }
            }            
        }
    }
    
    for(auto it = search.begin(); it != search.end(); it++) {
        if(it->second == "-") continue;
        answer += it->first.size();
    }
    
    return answer;
}