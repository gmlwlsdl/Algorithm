// 수빈이는 점 N에
// 동생은 점 K에
// X일 때 걸으면 1초 후에 X-1, X+1
// 순간이동 하면 1초 후에 2*X

#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;

int N, K;
vector<bool> checked(MAX);

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    checked[N] = true;

    while (!q.empty()) {
        int current = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (current == K) {
            cout << cnt << '\n';
            return;
        }

        if (current+1 < MAX && !checked[current+1]) {
            q.push(make_pair(current+1, cnt+1));
            checked[current+1] = true;
        }

        if (current-1 >= 0 && !checked[current-1]) {
            q.push(make_pair(current-1, cnt+1));
            checked[current-1] = true;
        }

        if (current*2 < MAX && !checked[current*2]) {
            q.push(make_pair(current*2, cnt+1));
            checked[current*2] = true;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    bfs();
}