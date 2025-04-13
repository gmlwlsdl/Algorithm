#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, totalCost = 0;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    while (pq.size() > 1) {
        int cost;
        
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        cost = a * b;
        totalCost += cost;
        pq.push(a+b);
    }

    cout << totalCost << '\n';

    return 0;
}

// a1, a2, an
// n개의 쇠막대
// x+y인 막대를 x, y 두 개로 자를 때는 xy의 비용이 든다.
// 현우는 최소의 비용으로 쇠막대를 잘라서 n개의 쇠막대를 얻고싶다

