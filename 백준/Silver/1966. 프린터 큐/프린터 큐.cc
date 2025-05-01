// 우선순위대로 출력
// 0 -> n 번째
// pair로 중요도, 자리 관리

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> files;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            int priority;
            cin >> priority;

            files.push({i, priority});
            pq.push(priority);
        }

        int cnt = 0;

        while (!files.empty()) {
            int curIdx = files.front().first;
            int curPri = files.front().second;

            files.pop();

            if (curPri == pq.top()) {
                pq.pop();
                cnt++;

                if (curIdx == m) {
                    cout << cnt << '\n';
                    break;
                }
            } else {
                files.push({curIdx, curPri});
            }
        }
    }

    return 0;
}