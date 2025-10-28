#include <vector>
#include <queue>

using namespace std;

// 상 하 좌 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs (int x, int y, int rows, int cols, vector<vector<int>> maps) {
    vector<vector<int>> dist(rows, vector<int>(cols, 0));
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    queue<pair<int, int>> q;
    
    q.push({x, y});
    visited[y][x] = 1;
    dist[y][x] = 1;
    
    while (!q.empty()) {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            
            if (nx < 0 || nx >= cols || ny < 0 || ny >= rows) {
                continue;
            }
            
            if (maps[ny][nx] == 1 && !visited[ny][nx]) {
                q.push({nx, ny});
                visited[ny][nx] = 1;
                dist[ny][nx] = dist[qy][qx] + 1;
            }
        }
    }
    
    return dist[rows - 1][cols - 1] == 0 ? -1 : dist[rows - 1][cols - 1];
}

int solution(vector<vector<int>> maps)
{
    int cols = maps[0].size();
    int rows = maps.size();
    
    return bfs(0, 0, rows, cols, maps);;
}