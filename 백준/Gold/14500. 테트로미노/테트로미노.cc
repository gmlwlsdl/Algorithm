#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, max_result = 0;

// 상 하 좌 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void calc1(vector<vector<int>> &v, vector<vector<bool>> &visited, int x, int y, int depth, int sum) {
    visited[x][y] = true;

    if (depth == 4) {
        visited[x][y] = false;
        max_result = max(max_result, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (!visited[nx][ny]) {
                calc1(v, visited, nx, ny, depth + 1, sum + v[nx][ny]);
            }
        }
    }

    visited[x][y] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            cin >> v[i][j];
        }
    }

    // ㅡ, ㅁ, ㄴ, ㄹ 처리
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            calc1(v, visited, i, j, 1, v[i][j]); 
        }
    }  
    
    // ㅗ 처리
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<int> neighbors;
            
            for (int r = 0; r < 4; r++) {
                int nx = i + dx[r];
                int ny = j + dy[r];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    neighbors.push_back(v[nx][ny]);
                }
            }
            
            int sum = v[i][j];
            if (neighbors.size() >= 3) {
                sort(neighbors.begin(), neighbors.end(), greater<int>());
                for (int z = 0; z < 3; z++) {
                    sum += neighbors[z];
                }
            }

            max_result = max(max_result, sum);
        }
    }

    cout << max_result << '\n';

    return 0;
}