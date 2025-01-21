#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string vps;
        stack<char> parentheses;
        cin >> vps;

        for (auto v:vps) {
            if (!parentheses.empty() && parentheses.top() == '(' && v == ')') {
                parentheses.pop();
            } else {
                parentheses.push(v);
            }
        }

        if (!parentheses.empty()) {
            cout << "NO" << '\n';
        } else if (parentheses.empty()) {
            cout << "YES" << '\n';
        }
    }

    return 0;
}