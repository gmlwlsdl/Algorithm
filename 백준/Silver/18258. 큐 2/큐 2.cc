#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    queue<int> que;

    for (int i = 0; i < N; i++) {
        string op;
        cin >> op;

        if (op.compare("push") == 0) {
            int x;
            cin >> x;
            que.push(x);
        } else if (op.compare("size") == 0) {
            cout << que.size() << '\n';
        } else if (op.compare("empty") == 0) {
            cout << que.empty() << '\n';
        } else if (op.compare("pop") == 0) {
            if (que.empty()) {
                cout << -1 << '\n';
            } else {
                cout << que.front() << '\n';
                que.pop();
            }
        } else if (op.compare("front") == 0) {
            if (que.empty()) {
                cout << -1 << '\n';
            } else {
                cout << que.front() << '\n';
            }
        } else if (op.compare("back") == 0) {
            if (que.empty()) {
                cout << -1 << '\n';
            } else {
                cout << que.back() << '\n';
            }
        }
    }

    return 0;
}