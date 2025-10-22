#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0, max_width = 0, max_length = 0;
    int length = sizes.size();
    
    for (int i = 0; i < length; i++) {
        if (sizes[i][0] > sizes[i][1]) {
            max_width = max(max_width, sizes[i][0]);
            max_length = max(max_length, sizes[i][1]);
        } else {
            max_width = max(max_width, sizes[i][1]);
            max_length = max(max_length, sizes[i][0]);
        }
        
    }
    
    return max_width * max_length;
}