#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int tc, w, h;
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

            if (ny >= 0 && ny < h && nx >= 0 && nx < w) {
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

        for (int i = 0; i < 4; i++) {
            int ny = qy + dy[i];
            int nx = qx + dx[i];

            if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
                cout << person_time[qy][qx] + 1 << '\n';
                return;
            }

            if (map[ny][nx] == '.' && person_time[ny][nx] == -1) {
                if (fire_time[ny][nx] == -1 || fire_time[ny][nx] > person_time[qy][qx] + 1) {
                    person_time[ny][nx] = person_time[qy][qx] + 1;
                    person_q.push({ny, nx});
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> tc;

    while (tc--) {
        cin >> w >> h;
        map.assign(h, vector<char>(w));
        fire_time.assign(h, vector<int>(w, -1));
        person_time.assign(h, vector<int>(w, -1));

        queue<pair<int, int>> fire_q, person_q;

        for (int y = 0; y < h; y++) {
            string row;
            cin >> row;
            for (int x = 0; x < w; x++) {
                map[y][x] = row[x];

                if (map[y][x] == '@') {
                    person_q.push({y, x});
                    person_time[y][x] = 0;
                }
                if (map[y][x] == '*') {
                    fire_q.push({y, x});
                    fire_time[y][x] = 0;
                }
            }
        }

        fire_bfs(fire_q);  
        person_bfs(person_q); 
    }

    return 0;
}