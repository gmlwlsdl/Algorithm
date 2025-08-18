#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 장르별 횟수 저장
    unordered_map<string, int> music;
    // 장르별로 무슨 노래가 몇 번 저장됐는지
    unordered_map<string, unordered_map<int, int>> musicList;
    
    for (int i = 0; i < genres.size(); i++) {
        music[genres[i]] += plays[i];
        musicList[genres[i]][i] = plays[i];
    }
    
    while (music.size() > 0) {
        string genre = {};
        int max = 0;
        
        // 장르 중에 제일 높은 값 찾기
        for (auto m: music) {
            if (max < m.second) {
                max = m.second;
                genre = m.first;
            }
        }
        
        // 최대 2곡
        for (int i = 0; i < 2; i++) {
            int val = 0, ind = -1;
                
            // 노래 중에 제일 높은 값 찾기
            for (auto ml: musicList[genre]) {
                // 같은 재생 횟수이면 낮은 인덱스로 선택
                if (val < ml.second || (val == ml.second && (ind == -1 || ml.first < ind))) {
                    val = ml.second;
                    ind = ml.first;
                }
            }
            
            // 노래가 0 ~ 1곡이라면 끝
            if (ind == -1) {
                break;
            }
            
            answer.push_back(ind);
            musicList[genre].erase(ind);
        }
        
        music.erase(genre);
    }
    return answer;
}