#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, count = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        stack<char> words;
        string word;
        cin >> word;

        for (auto w : word) {
            if (!words.empty() && words.top() == w) {
                words.pop();
            } else {
                words.push(w);
            }
        }
        if (words.empty()) {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}