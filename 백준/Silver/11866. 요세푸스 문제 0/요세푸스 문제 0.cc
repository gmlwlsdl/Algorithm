#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    deque<int> deq;

    for (int i = 1; i <= n; i++) {
        deq.push_back(i);
    }

    cout << "<";

    while (!deq.empty()) {
        for (int i = 1; i < k; i++) {
            // k 보다 앞에 있던 애들 뒤로 보내고
            deq.push_back(deq.front());
            
            // 원래 있던 자리에서 삭제
            deq.pop_front();
        }

        cout << deq.front();
        deq.pop_front();

        if (!deq.empty()) cout << ", ";
    }

    cout << ">" << '\n';

    return 0;
}