#include <iostream>
#include <stack>
#include <string> 

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    stack<int> stack;

    for (int i = 0; i < N; i++) {
        string op; 
        cin >> op;

        if (op == "push") {
            int num;
            cin >> num;
            stack.push(num);
        } else if (op == "pop") {
            if (stack.empty()) {
                cout << -1 << '\n';
            } else {
                cout << stack.top() << '\n';
                stack.pop();
            }
        } else if (op == "size") {
            cout << stack.size() << '\n';
        } else if (op == "empty") {
            cout << (stack.empty() ? 1 : 0) << '\n';
        } else if (op == "top") {
            if (stack.empty()) {
                cout << -1 << '\n';
            } else {
                cout << stack.top() << '\n';
            }
        }
    }

    return 0;
}