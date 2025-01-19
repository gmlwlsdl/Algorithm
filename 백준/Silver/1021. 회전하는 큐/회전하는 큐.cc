#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, num, idx, count = 0;
    cin >> N >> M;

    deque<int> deq;

    for (int i = 1; i <= N; i++) {
        deq.push_back(i);
    }

    for (int m = 0; m < M; m++) {
        cin >> num;

        for (int i = 0; i < deq.size(); i++) {
            if (deq[i] == num) {
                idx = i;
                break;
            }
        }

        if (idx < deq.size() - idx) {
            while (deq.front() != num) {
                count++;
                deq.push_back(deq.front());
                deq.pop_front();
            }
        } else {
            while (deq.front() != num) {
                count++;
                deq.push_front(deq.back());
                deq.pop_back();
            }
        }

        deq.pop_front();
    }

    cout << count << '\n';

    return 0;
}