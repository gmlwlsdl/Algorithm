#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m; 
int start_row, start_col;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

vector<vector<int>> map;
vector<vector<int>> dist;
vector<vector<bool>> visited;

void bfs() {
    queue<pair<int, int>> q;
    q.push({start_row, start_col});
    visited[start_row][start_col] = true;
    dist[start_row][start_col] = 0;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (visited[nr][nc]) continue;
            if (map[nr][nc] == 0) continue;

            visited[nr][nc] = true;
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m; 

    map.assign(n, vector<int>(m));
    dist.assign(n, vector<int>(m, -1));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                start_row = i;
                start_col = j;
                dist[i][j] = 0;
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) cout << 0;
            else if (!visited[i][j]) cout << -1;
            else cout << dist[i][j];

            if (j != m - 1) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}