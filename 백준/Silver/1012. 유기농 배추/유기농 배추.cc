#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int tc, m, n, k, total;
vector<vector<bool>> field;
vector<vector<bool>> checked;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    checked[y][x] = true;

    while (!q.empty()) {
        int qy = q.front().first;
        int qx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = qy + dy[i];
            int nx = qx + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && !checked[ny][nx] && field[ny][nx]) {
                checked[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> tc;

    while (tc--) {
        total = 0;
        cin >> m >> n >> k;

        field.assign(n, vector<bool>(m, false));
        checked.assign(n, vector<bool>(m, false));

        while (k--) {
            int x, y;
            cin >> x >> y;
            field[y][x] = true;  
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] && !checked[i][j]) {  
                    bfs(i, j);
                    total++;
                }
            }
        }

        cout << total << '\n';
    }

    return 0;
}