#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    for (int s : scoville) {
        pq.push(s);
    }

    int count = 0;

    // 최솟값이 K 이상이면 바로 0 반환
    if (!pq.empty() && pq.top() >= K) {
        return 0;
    }

    while (pq.size() >= 2 && pq.top() < K) {
        long long first  = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();

        long long mixed = first + 2LL * second;
        pq.push(mixed);
        ++count;
    }

    if (!pq.empty() && pq.top() >= K) {
        return count;
    }
    
    return -1; 
}