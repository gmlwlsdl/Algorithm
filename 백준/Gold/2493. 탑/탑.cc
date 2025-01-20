#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    stack<pair<int, int>> top;

    for (int i = 0; i < N; i++) {
        int height;
        cin >> height;

        while (!top.empty() && top.top().second <= height) {
            top.pop();
        }

        if (top.empty()) {
            cout << 0 << ' '; 
        } else {
            cout << top.top().first << ' '; 
        }

        top.push({i + 1, height}); 
    }

    return 0;
}