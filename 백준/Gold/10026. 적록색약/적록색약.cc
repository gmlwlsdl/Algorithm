#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<vector<char>> rgb;
vector<vector<bool>> checked;

int n;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void bfs(int y, int x, bool isBlind) {
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    checked[y][x] = true;

    char color = rgb[y][x];

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < n && !checked[ny][nx]) {
                if (isBlind) {
                    // 색약인 경우
                    if ((color == 'R' || color == 'G') && (rgb[ny][nx] == 'R' || rgb[ny][nx] == 'G')) {
                        checked[ny][nx] = true;
                        q.push({ny, nx});
                    } else if (rgb[ny][nx] == color && color == 'B') {
                        checked[ny][nx] = true;
                        q.push({ny, nx});
                    }
                } else {
                    // 색약이 아닌 경우
                    if (rgb[ny][nx] == color) {
                        checked[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }
}

int main () {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    rgb.resize(n, vector<char>(n));
    checked.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < n; j++) {
            rgb[i][j] = str[j];
        }
    }

    int blind = 0, nonBlind = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!checked[i][j]) {
                bfs(i, j, false);
                nonBlind++;
            }
        }
    }

    checked.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!checked[i][j]) {
                bfs(i, j, true);
                blind++;
            }
        }
    }

    cout << nonBlind << ' ' << blind << '\n';

    return 0;
}