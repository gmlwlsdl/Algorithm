#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int h = 0;
    
    sort(citations.rbegin(), citations.rend()); // 내림차순

    for (int i = 0; i < (int)citations.size(); i++) {
        int candidate = i + 1;               // h 후보
        
        if (citations[i] >= candidate) {
            h = candidate;                    // 더 큰 h로 갱신
        } else {
            break;                            // 이후는 더 작으니 불가능
        }
    }
    
    return h;
}