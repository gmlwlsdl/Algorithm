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

    queue<int> card;

    for (int i = 1; i <= N; i++) {
        card.push(i);
    }

    while (!card.empty()) {
        if (card.size() > 1) {
            card.pop();
            int move = card.front();
            card.pop();
            card.push(move);
        }
        if (card.size() == 1) {
            cout << card.front() << '\n';
            break;
        }
    }

    return 0;
}