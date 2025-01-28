#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int tc, n, x, y, goal_x, goal_y;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

vector<vector<int>> cnt;
vector<vector<bool>> checked;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    checked[x][y] = true;

    while(!q.empty()) {
        int qx = q.front().first;
        int qy = q.front().second;
        
        q.pop();

        if (qx == goal_x && qy == goal_y) {
            cout << cnt[qx][qy] << '\n';
            return;
        }

        for (int i = 0; i < 8; i++) {
            int nx = qx + dx[i];
            int ny = qy + dy[i];

            if (nx < n && nx >= 0 && ny < n && ny >= 0 && !checked[nx][ny]) {
                checked[nx][ny] = true;
                q.push(make_pair(nx, ny));
                cnt[nx][ny] = cnt[qx][qy] + 1;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> tc;

    while (tc--) {
        cin >> n;
        
        cnt.assign(n, vector<int>(n, 0));
        checked.assign(n, vector<bool>(n, false));
        cin >> x >> y >> goal_x >> goal_y;
        bfs(x, y);
    }

    return 0;
}