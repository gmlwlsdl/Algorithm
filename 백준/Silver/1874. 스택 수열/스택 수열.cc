#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, max = 0;
    cin >> N;

    stack<int> stack;
    vector<char> op;

    for (int i = 0; i < N; i++) {
        int goal;
        cin >> goal;

        if (goal > max) {
            for (int j = max + 1; j <= goal; j++) {
                stack.push(j);
                op.push_back('+');
            }
            max = goal; 
        }

        if (!stack.empty() && stack.top() == goal) {
            stack.pop();
            op.push_back('-');
        } else {
            cout << "NO" << '\n';
            return 0;
        }
    }

    for (char result : op) {
        cout << result << '\n';
    }

    return 0;
}