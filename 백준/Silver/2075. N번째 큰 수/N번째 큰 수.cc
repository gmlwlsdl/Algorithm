#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n * n; i++) {
        int a;
        cin >> a;

        pq.push(a);

        if (pq.size() > n) {
            pq.pop();
        }
    }

    cout << pq.top() << '\n';

    return 0;
}