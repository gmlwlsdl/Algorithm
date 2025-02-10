#include <iostream>
#include <vector>
#include <queue>
#include <tuple> 

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int N, int M, vector<vector<int>> &maze) {
    vector<vector<vector<int>>> visited(N, vector<vector<int>>(M, vector<int>(2, 0)));
    queue<tuple<int, int, int>> q; // x y 벽 부순 상태

    q.push({0, 0, 0});
    visited[0][0][0] = 1; // 시작 지점 방문함

    while (!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front();
        q.pop();

        if (x == N - 1 && y == M - 1) {
            return visited[x][y][broken];
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }

            // 벽이 아니고 방문도 아직 안 함
            if (maze[nx][ny] == 0 && visited[nx][ny][broken] == 0) {
                visited[nx][ny][broken] = visited[x][y][broken] + 1;
                q.push({nx, ny, broken});
            }

            // 벽이고 아직 부순 벽이 없는 경우
            if (maze[nx][ny] == 1 && broken == 0 && visited[nx][ny][1] == 0) {
                visited[nx][ny][1] = visited[x][y][broken] + 1;
                q.push({nx, ny, 1});
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> maze(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            maze[i][j] = row[j] - '0'; 
        }
    }

    cout << bfs(N, M, maze) << '\n';

    return 0;
}