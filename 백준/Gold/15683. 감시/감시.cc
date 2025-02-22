// n*m 직사각형
// 1*1 사무실에는 총 k개의 cctv

// cctv는 5가지 종류
// 1. 한 방향
// 2. 두 방향 1 (상하, 좌우)
// 3. 두 방향 2 (상우, 상좌, 하우, 하좌)
// 4. 세 방향 (좌상우, 상우하, 우하좌, 하좌상)
// 5. 네 방향
// 감시하는 방향의 칸 전체를 감시할 수 잇음 -> 이게 불가하면 사각지대
// 벽 통과는 못 함
// 회전은 90도만

// 0 빈칸, 6 벽, 1~5 cctv, # 감시가능영역
// cctv는 겹칠 수 잇음
// 사각지대 최소값 구하기 -> 감시 못하는 칸 최소 -> 최대한 많은 감시가능칸


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, ans = 987654321;
vector<vector<int>> office;
vector<pair<int, int>> cctv;

int dx[4] = {0, -1, 0, 1}; // 우 상 좌 하
int dy[4] = {1, 0, -1, 0};

void check(int x, int y, int dir, vector<vector<bool>> &monitered) {
    dir %= 4;

    while (1) {
        x += dx[dir];
        y += dy[dir];

        if (x < 0 || x >= n || y < 0 || y >= m) return;
        if (office[x][y] == 6) return;
        if (office[x][y] != 0) continue;
        monitered[x][y] = true;
    }
}

void watch(int idx, vector<vector<bool>> monitered) {
    if (idx == cctv.size()) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!monitered[i][j] && office[i][j] == 0) { // cctv랑 벽은 빼야 하니까
                    cnt++;
                }
            }
        }

        ans = min(ans, cnt);
        return;
    }

        int qx = cctv[idx].first;
        int qy = cctv[idx].second;

        for (int dir = 0; dir < 4; dir++) {
            vector<vector<bool>> backup = monitered;  // 현재 상태 저장
    
            if (office[qx][qy] == 1)
                check(qx, qy, dir, monitered);
            else if (office[qx][qy] == 2) {
                check(qx, qy, dir, monitered);
                check(qx, qy, dir + 2, monitered); // 현재, 현재 반대 방향
            }
            else if (office[qx][qy] == 3) {
                check(qx, qy, dir, monitered);
                check(qx, qy, dir + 1, monitered); // 현재, 현재 기준 직각 방향
            }
            else if (office[qx][qy] == 4) {
                check(qx, qy, dir, monitered);
                check(qx, qy, dir + 1, monitered);
                check(qx, qy, dir + 2, monitered); // 현재, 현재 기준 직각, 현재 반대 방향
            }
            else if (office[qx][qy] == 5) {
                check(qx, qy, dir, monitered);
                check(qx, qy, dir + 1, monitered);
                check(qx, qy, dir + 2, monitered);
                check(qx, qy, dir + 3, monitered); // 모든 방향
            }
    
            watch(idx + 1, monitered);
            monitered = backup;
        }
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    office.assign(n, vector<int>(m, 0));
    vector<vector<bool>> monitered(n, vector<bool>(m, false)); // 감시중인지

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> office[i][j]; // (3, 4) 3번째 행 4번째 열

            // 감시카메라면 벡터에 추가
            if (0 < office[i][j] && office[i][j] < 6) {
                cctv.push_back({i, j});
            }
        }
    }

    watch(0, monitered);

    cout << ans << '\n';

    return 0;
}