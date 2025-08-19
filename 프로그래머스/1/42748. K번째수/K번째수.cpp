#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto c: commands) {
        vector<int> list;
        
        for (int i = c[0] - 1; i < c[1]; i++) {
            list.push_back(array[i]);
        }
        
        sort(list.begin(), list.end());
        
        answer.push_back(list[c[2] - 1]);
    }
    
    return answer;
}