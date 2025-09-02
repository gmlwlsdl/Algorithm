#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    unordered_set<int> lostSet(lost.begin(), lost.end());
    unordered_set<int> reserveSet(reserve.begin(), reserve.end());
    
    for (auto r: reserve) {
        if (lostSet.count(r)) {
            lostSet.erase(r);
            reserveSet.erase(r);
        }
    }
    
    for (auto r: reserve) {
        if (!reserveSet.count(r)) continue; // 이미 빌려줬으니까 넘어감
        
        int left = r - 1, right = r + 1;
        
        if (left >= 1 && lostSet.count(left)) {
            lostSet.erase(left);
        } else if (right <= n && lostSet.count(right)) {
            lostSet.erase(right);    
        }
    }
    
    int answer = n - lostSet.size();
    
    return answer;
}