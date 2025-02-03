#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
vector<vector<bool>> map;
vector<int> areas; 

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int bfs(int start_x, int start_y) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    map[start_x][start_y] = true;

    int area_size = 1; 

    while (!q.empty()) {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = qx + dx[i];
            int ny = qy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !map[nx][ny]) {
                map[nx][ny] = true;
                q.push({nx, ny});
                area_size++;
            }
        }
    }

    return area_size;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;

    map.assign(n, vector<bool>(m, false));

    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                map[y][x] = true; 
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!map[i][j]) { 
                areas.push_back(bfs(i, j)); 
            }
        }
    }

    sort(areas.begin(), areas.end()); 
    
    cout << areas.size() << '\n'; 

    for (int area : areas) {
        cout << area << " ";
    }

    return 0;
}