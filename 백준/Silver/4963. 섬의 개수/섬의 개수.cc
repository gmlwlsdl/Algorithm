#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int w, h;
int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1}; // 상하좌우 + 대각선
int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};

vector<vector<int>> maps;
vector<vector<bool>> visited;


void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto [qx, qy] = q.front();
        q.pop();

        for (int z = 0; z < 8; z++) {
            int nx = qx + dx[z];
            int ny = qy + dy[z];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (visited[nx][ny]) continue;
            if (maps[nx][ny] == 0) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        int cnt = 0;

        maps.assign(h, vector<int>(w, 0));
        visited.assign(h, vector<bool>(w, false));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int val;
                cin >> val;
                maps[i][j] = val;
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (maps[i][j] && !visited[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}