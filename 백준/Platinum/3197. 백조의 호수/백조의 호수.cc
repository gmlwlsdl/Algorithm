#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int R, C;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<vector<char>> ice;
vector<vector<bool>> swan_visited;
vector<vector<bool>> water_visited;

queue<pair<int, int>> swan, next_swan;
queue<pair<int, int>> water;

bool bfs() {
    while (!swan.empty()) {
        int y = swan.front().first;
        int x = swan.front().second;
        swan.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C || swan_visited[ny][nx]) {
                continue;
            }

            swan_visited[ny][nx] = true;

            if (ice[ny][nx] == 'L') {
                return true;  
            }

            if (ice[ny][nx] == '.') {
                swan.push({ny, nx}); 
            } else if (ice[ny][nx] == 'X') {
                next_swan.push({ny, nx});  
            }
        }
    }

    return false;
}

void melt() {
    int size = water.size();
    for (int i = 0; i < size; i++) {
        int y = water.front().first;
        int x = water.front().second;
        water.pop();

        for (int j = 0; j < 4; j++) {
            int ny = y + dy[j];
            int nx = x + dx[j];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C || water_visited[ny][nx]) {
                continue;
            }

            if (ice[ny][nx] == 'X') {
                ice[ny][nx] = '.';  
                water.push({ny, nx});
                water_visited[ny][nx] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    ice.assign(R, vector<char>(C));
    swan_visited.assign(R, vector<bool>(C, false));
    water_visited.assign(R, vector<bool>(C, false));

    pair<int, int> start, end;
    bool found_first_swan = false;

    for (int i = 0; i < R; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < C; j++) {
            ice[i][j] = row[j];
            if (ice[i][j] == 'L') {
                if (!found_first_swan) {
                    start = {i, j};
                    swan.push({i, j});
                    swan_visited[i][j] = true;
                    found_first_swan = true;
                } else {
                    end = {i, j};
                }
            }
            if (ice[i][j] == '.' || ice[i][j] == 'L') {
                water.push({i, j});
                water_visited[i][j] = true;
            }
        }
    }

    int days = 0;

    while (true) {
        if (bfs()) { // 백조 이동
            cout << days << '\n';
            break;
        }

        // 물 녹이고
        melt(); 

        swan = next_swan;
        next_swan = queue<pair<int, int>>(); // 다음 이동 초기화 해두기

        days++;
    }

    return 0;
}