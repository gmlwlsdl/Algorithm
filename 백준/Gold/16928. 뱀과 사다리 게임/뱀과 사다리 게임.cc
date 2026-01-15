#include <iostream>
#include <map>
#include <queue>

using namespace std;

int d[6] = {1, 2, 3, 4, 5, 6};
map<int, int> ladder;
map<int, int> snake;

void bfs(int start) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    bool visited[101] = {false, };

    while (!q.empty()) {
        int qx = q.front().first;
        int qcnt = q.front().second;
        q.pop();

        if (qx == 100) {
            cout << qcnt << '\n';
            return ;
        }

        for (int i = 0; i < 6; i++) {
            int nx = qx + d[i];

            if (nx < 101) {
                if (ladder[nx]) nx = ladder[nx];
                else if (snake[nx]) nx = snake[nx];
                
                if (!visited[nx]) {
                    visited[nx] = true;
                    q.push({nx, qcnt + 1});
                }
                
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a] = b;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        snake[a] = b;
    }

    bfs(1);

    return 0;
}