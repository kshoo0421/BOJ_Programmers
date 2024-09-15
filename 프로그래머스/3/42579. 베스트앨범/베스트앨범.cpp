#include <bits/stdc++.h>
using namespace std;

struct Music {
    int index;
    int play;
    string genre;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<Music> musics(genres.size());
    unordered_map<string, int> um;
    for(int i = 0; i < genres.size(); i++) {
        musics[i].index = i;
        musics[i].genre = genres[i];
        musics[i].play = plays[i];
        um[genres[i]] += plays[i];
    }
    
    sort(musics.begin(), musics.end(), [&](Music& m1, Music& m2){
        if(um[m1.genre] != um[m2.genre]) return um[m1.genre] > um[m2.genre];
        if(m1.play != m2.play) return m1.play > m2.play;
        return m1.index < m2.index;
    });
    
    vector<int> answer;
    
    int cnt = 0;
    string s = "";    
    for(auto& m : musics) {
        if(s == m.genre) {
            if(cnt == 2) continue;
            cnt++;
        }
        else {
            s = m.genre;
            cnt = 1;
        }
        answer.emplace_back(m.index);
    }
    
    return answer;
}