#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, h, cnt = 0;
vector<vector<vector<int>>> box;

// 위 아래 왼 오 앞 뒤
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};
int dh[6] = {1, -1, 0, 0, 0, 0};

int bfs() {
    queue<pair<pair<int, int>, int>> q;
    int noMato = 0;  // 익지 않은 토마토 개수

    for (int z = 0; z < h; z++) { // 높이(h)
        for (int y = 0; y < n; y++) { // 행(n)
            for (int x = 0; x < m; x++) { // 열(m)
                if (box[z][y][x] == 1) {
                    q.push({{z, y}, x}); // 익은 토마토 추가
                } else if (box[z][y][x] == 0) {
                    noMato++;  // 익지 않은 토마토 개수 카운트
                }
            }
        }
    }

    if (noMato == 0) return 0; // 이미 모든 토마토가 익었으면 0

    while (!q.empty()) {
        int size = q.size();
        bool noMatodays = false;

        for (int j = 0; j < size; j++) {
            int qh = q.front().first.first;
            int qy = q.front().first.second;
            int qx = q.front().second;
            q.pop();

            for (int i = 0; i < 6; i++) {
                int nh = qh + dh[i];
                int ny = qy + dy[i];
                int nx = qx + dx[i];

                if (nh >= 0 && nh < h && ny >= 0 && ny < n && nx >= 0 && nx < m 
                && box[nh][ny][nx] == 0) {
                    box[nh][ny][nx] = 1;
                    q.push({{nh, ny}, nx});
                    noMato--;
                    noMatodays = true;
                }
            }
        }

        if (noMatodays) cnt++;
    }

    return (noMato > 0) ? -1 : cnt; // 익지 않은 토마토가 남으면 -1 반환
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n >> h; // 열(m), 행(n), 높이(h)

    box.assign(h, vector<vector<int>>(n, vector<int>(m)));

    for (int z = 0; z < h; z++) { // 높이(h)
        for (int y = 0; y < n; y++) { // 행(n)
            for (int x = 0; x < m; x++) { // 열(m)
                cin >> box[z][y][x];
            }
        }
    }

    cout << bfs() << '\n';
    return 0;
}