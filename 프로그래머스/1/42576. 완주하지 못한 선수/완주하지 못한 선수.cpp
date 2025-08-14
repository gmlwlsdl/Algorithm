// 참여한 선수는 participant
// 완주한 선수는 completion
// 완주 못한 선수를 return 하라

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i]) {
            answer = participant[i];
            return answer;
        }    
    }
    
    return participant.back();
}