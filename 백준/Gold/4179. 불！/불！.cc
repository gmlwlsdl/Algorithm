#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n, m;
vector<vector<char>> map;
vector<vector<int>> fire_time;
vector<vector<int>> person_time;

// 동 서 남 북
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void fire_bfs(queue<pair<int, int>> &fire_q) {
    while (!fire_q.empty()) {
        int qy = fire_q.front().first;
        int qx = fire_q.front().second;
        fire_q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = qy + dy[i];
            int nx = qx + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                if (map[ny][nx] != '#' && fire_time[ny][nx] == -1) {
                    fire_time[ny][nx] = fire_time[qy][qx] + 1;
                    fire_q.push({ny, nx});
                }
            }
        }
    }
}

void person_bfs(queue<pair<int, int>> &person_q) {
    while (!person_q.empty()) {
        int qy = person_q.front().first;
        int qx = person_q.front().second;
        person_q.pop();

        if (qy == 0 || qy == n - 1 || qx == 0 || qx == m - 1) {
            cout << person_time[qy][qx] + 1 << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = qy + dy[i];
            int nx = qx + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                if (map[ny][nx] == '.' && person_time[ny][nx] == -1) {
                    if (fire_time[ny][nx] == -1 || fire_time[ny][nx] > person_time[qy][qx] + 1) {
                        person_time[ny][nx] = person_time[qy][qx] + 1;
                        person_q.push({ny, nx});
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    map.assign(n, vector<char>(m, '.')); 
    fire_time.assign(n, vector<int>(m, -1));
    person_time.assign(n, vector<int>(m, -1));

    queue<pair<int, int>> fire_q, person_q;

    for (int y = 0; y < n; y++) {
        string row;
        cin >> row;

        for (int x = 0; x < m; x++) {
            map[y][x] = row[x];

            if (map[y][x] == 'J') { 
                person_q.push({y, x});
                person_time[y][x] = 0; 
            }

            if (map[y][x] == 'F') { 
                fire_q.push({y, x});
                fire_time[y][x] = 0; 
            }
        }
    }

    fire_bfs(fire_q);
    person_bfs(person_q); 

    return 0;
}