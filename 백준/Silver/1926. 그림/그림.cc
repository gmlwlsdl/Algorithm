#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int map[501][501] = {0, };
bool visited[501][501] = {0, };
queue<pair<int, int>> q; // BFS용 큐
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int s = 1;
vector<int> vec;

void BFS(int y, int x) {
    visited[y][x] = true;
    q.push(make_pair(y, x));

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                continue;
            }

            if (map[ny][nx] == 1 && visited[ny][nx] == false) {
                visited[ny][nx] = true;
                s++;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

bool compare(int a, int b) {
    return a > b;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j< m; j++) {
            cin >> map[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j< m; j++) {
            if (map[i][j] == 1 && visited[i][j] == false) {
                BFS(i ,j);
                vec.push_back(s);
                cnt++;
                s = 1;            
            }

        }
    }

    sort(vec.begin(), vec.end(), compare); // 오름차순 정렬

    cout << cnt << '\n';

    if (cnt == 0) {
        cout << 0 << '\n';
    } else {
        cout << vec[0] << '\n';
    }
}