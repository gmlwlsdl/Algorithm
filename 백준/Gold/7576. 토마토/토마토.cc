#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n, cnt = -1;
vector<vector<int>> box;
vector<vector<bool>> checked;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs() {
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == 1) {
                q.push(make_pair(i, j));
                checked[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        int size = q.size(); 
        cnt++; 

        for (int i = 0; i < size; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && box[ny][nx] == 0) {
                    q.push(make_pair(ny, nx));
                    box[ny][nx] = 1;  
                }
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == 0) {
                return -1;  // 익지 않은 토마토
            }
        }
    }

    return cnt;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;

    // n행 m열
    box.assign(n, vector<int>(m, 0));
    checked.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {  // 행
        for (int j = 0; j < m; j++) {  // 열
            cin >> box[i][j];
        }
    }

    cout << bfs() << '\n';
    return 0;
}