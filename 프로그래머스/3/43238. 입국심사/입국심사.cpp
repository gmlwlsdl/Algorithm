#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long min = 1, max = (long long)n * (*max_element(times.begin(), times.end()));
    long long mid;
    long long result = max; // 실행 시간
    long long total; // 해당 시간에 심사를 받을 수 있는 사람의 수
    
    while (min <= max) {
        total = 0;
        mid = (max + min) / 2;
        
        for (auto t: times) {
            total += mid / t;
            
            if (total >= n) {
                break;
            }
        }
        
        if (total >= n) {
            result = mid;
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }
    
    return result;
}