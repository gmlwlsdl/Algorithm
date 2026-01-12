// 사이클 만들 수 있으면 YES, 아니면 NO

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int dx[4] = {0, 0, -1, 1}; // 좌 우 상 하
int dy[4] {-1, 1, 0, 0}; // 좌 우 상 하
vector<vector<bool>> visited;

bool dfs(int x, int y, int px, int py, vector<vector<char>> &two_dots) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (two_dots[x][y] == two_dots[nx][ny]) {
            if (!visited[nx][ny]) {
                if (dfs(nx, ny, x, y, two_dots)) return true;
            } else {
                if (nx != px || ny != py) { 
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vector<vector<char>> two_dots(n, vector<char>(m,'-'));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> two_dots[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                if (dfs(i, j, -1, -1, two_dots)) {
                    cout << "Yes" << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "No" << '\n';

    return 0;
}