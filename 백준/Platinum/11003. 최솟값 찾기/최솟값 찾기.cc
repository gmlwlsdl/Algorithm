#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    deque<int> dq; 
    vector<int> result; 

    for (int i = 0; i < N; i++) {
        if (!dq.empty() && dq.front() < i - L + 1) {
            dq.pop_front();
        }

        while (!dq.empty() && A[dq.back()] > A[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        result.push_back(A[dq.front()]);
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << '\n';

    return 0;
}