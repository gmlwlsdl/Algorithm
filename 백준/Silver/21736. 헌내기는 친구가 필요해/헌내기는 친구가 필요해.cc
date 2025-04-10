#include <iostream>
#include <queue>

using namespace std;

int n, m, cnt = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool visited[601][601] = {false};
char map[601][601] = {0};

bool bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int qx = q.front().first;
        int qy = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = qx + dx[i];
            int ny = qy + dy[i];

            if ( 0 > nx | nx >= n | 0 > ny | ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (map[nx][ny] == 'X') continue;

            if (map[nx][ny] == 'P') cnt++;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return cnt == 0 ? false : true;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int d_x, d_y;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'I') {
                d_x = i;
                d_y = j;
            }
        }
    }

    if (!bfs(d_x, d_y)) {
        cout << "TT" << '\n';
    } else {
        cout << cnt << '\n';
    };
   
    return 0;
}