#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m;
int maze[101][101] = {0, };
bool visited[101][101] = {0, };
int dist[101][101] = {0, };

int x_move[4] = {1, -1, 0, 0};
int y_move[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

void bfs(int y, int x) {
    visited[y][x] = true;
    q.push(make_pair(y, x));
    dist[y][x]++;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_y = y + y_move[i];
            int next_x = x + x_move[i];

            if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m) {
                continue;
            }

            if (maze[next_y][next_x] == 1 && !visited[next_y][next_x]) {
                visited[next_y][next_x] = true;
                q.push(make_pair(next_y, next_x));
                dist[next_y][next_x] = dist[y][x] + 1;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            maze[i][j] = s[j] - '0';
        }
    }

    bfs(0, 0);

    cout << dist[n - 1][m - 1] << '\n';
}