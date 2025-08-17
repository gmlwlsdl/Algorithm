#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> count;
    
    for (auto c: clothes) {
        count[c[1]]++;
    }
    
    int answer = 1;
    for (auto c: count) {
        answer *= c.second + 1;
    }
    
    return answer - 1;
}