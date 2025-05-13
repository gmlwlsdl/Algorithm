// 오른쪽 또는 아래쪽으로만 이동
// 1은 가능 0은 불가능
// 0,0 시작
// n-1, m-1은 도착

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> city;
vector<vector<bool>> visited;

bool dfs(int x, int y) {
    // 도착지점 도달 시
    if (x == m - 1 && y == n - 1) {
        return true;
    }

    // 범위 벗어나거나, 벽이거나, 이미 방문한 경우
    if (x < 0 || x >= m || y < 0 || y >= n || city[x][y] == 0 || visited[x][y]) {
        return false;
    }

    // 방문 처리
    visited[x][y] = true;

    // 아래쪽 이동
    if (dfs(x + 1, y)) {
        return true;
    }

    // 오른쪽 이동
    if (dfs(x, y + 1)) {
        return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    city.assign(m, vector<int>(n, 0));
    visited.assign(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
        }
    }

    if (dfs(0, 0)) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }

    return 0;
}