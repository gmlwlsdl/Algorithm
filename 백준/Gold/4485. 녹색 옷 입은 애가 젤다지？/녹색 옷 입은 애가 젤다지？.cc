// 0,0 > n-1, n-1
// 도둑루피를 만나면 돈을 잃음
// 링크는 잃는 금액을 최소로 해야 함

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, cnt = 1, result = 0;

// 상 하 좌 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(vector<vector <int>> rupee) {
    queue<pair<int, int>> q;
    vector<vector<int>> zelda(n, vector<int>(n, 1e9)); // 완즈니 큰 값으로 초기화

    q.push({0, 0});
    zelda[0][0] = rupee[0][0];

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                // 이미 기록된 다음 칸에서 잃을 비용보다
                // 현재까지 잃은 루피 + 다음 칸에서 잃을 루피가
                // 더 작은 경우에는 이동!
                if (zelda[nx][ny] > zelda[cur.first][cur.second] + rupee[nx][ny]) {
                    zelda[nx][ny] = zelda[cur.first][cur.second] + rupee[nx][ny];
                    q.push({nx, ny});
                }

            }
        }
    }

    cout << "Problem " << cnt++ << ": " << zelda[n - 1][n - 1] << '\n';
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (1) {
        cin >> n;

        if (!n) break;

        vector<vector <int>> rupee;
        rupee.assign(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> rupee[i][j];
            }
        }

        bfs(rupee);
    }

    return 0;
}