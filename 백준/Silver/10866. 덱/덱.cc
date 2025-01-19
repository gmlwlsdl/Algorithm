#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    deque<int> deq;

    for (int i = 0; i < N; i++) {
        string op;
        cin >> op;

        if (op == "push_front") {
            int x;
            cin >> x;
            deq.push_front(x);
        } else if (op == "push_back") {
            int x;
            cin >> x;
            deq.push_back(x);
        } else if (op == "pop_front") {
            if (deq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
        } else if (op == "pop_back") {
            if (deq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << deq.back() << '\n';
                deq.pop_back();
            }
        } else if (op == "size") {
            cout << deq.size() << '\n';
        } else if (op == "empty") {
            cout << deq.empty() << '\n';
        } else if (op == "front") {
            if (deq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << deq.front() << '\n';
            }
        } else if (op == "back") {
            if (deq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << deq.back() << '\n';
            }
        }
    }

    return 0;
}