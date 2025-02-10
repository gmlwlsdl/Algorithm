// L 높이 R 세로 C 가로
// # 금 . 빈공간
// S 출발점 E 도착점

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<vector<char>>> building;
vector<vector<vector<bool>>> visited;
queue<pair<int, pair<int, int>>> start;

int dx[6] = {0, 0, 0, 0, 1, -1}; // 상 하 북 남 동 서
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

void bfs() {
    int time = 0;

    while (!start.empty()) {
        int size = start.size();

        for (int i = 0; i < size; i++) {
            int z = start.front().first;
            int y = start.front().second.first;
            int x = start.front().second.second;
            start.pop();

            for (int j = 0; j < 6; j++) {
                int nz = z + dz[j];
                int ny = y + dy[j];
                int nx = x + dx[j];

                if (nz < 0 || ny < 0 || nx < 0 || nz >= building.size() || ny >= building[0].size() || nx >= building[0][0].size()) {
                    continue;
                }

                if (building[nz][ny][nx] == 'E') {
                    cout << "Escaped in " << time + 1 << " minute(s)." << '\n';
                    return;
                }

                if (building[nz][ny][nx] == '.' && !visited[nz][ny][nx]) {
                    visited[nz][ny][nx] = true;
                    start.push({nz, {ny, nx}});
                }
            }
        }
        time++;
    }

    cout << "Trapped!" << '\n';
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (true) {
        int L, R, C;
        cin >> L >> R >> C;

        if (L == 0 && R == 0 && C == 0) break;

        building.assign(L, vector<vector<char>>(R, vector<char>(C, 0)));
        visited.assign(L, vector<vector<bool>>(R, vector<bool>(C, false)));

        while (!start.empty()) {
            start.pop(); 
        }

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    cin >> building[i][j][k]; // 높이 세로 가로 

                    if (building[i][j][k] == 'S') {
                        start.push({i, {j, k}});
                        visited[i][j][k] = true;
                    }
                }
            }
        }

        bfs();
    }

    return 0;
}