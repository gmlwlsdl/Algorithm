// 1은 집이 있는 곳
// 0은 집이 없는 곳
// 단지에 번호를 붙일 것임
// 상하좌우에 집이 있으면 연결된 것
// 몇 개의 단지가 있는지
// 1단지부터 집이 몇 개 있는지

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, cnt, res, num = 0;

// 상하좌우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<vector <int>> maps;
vector<vector <int>> visited;
vector<int> groups;

void dfs(int x, int y) {

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (maps[ny][nx] && !visited[ny][nx]) {
                cnt++;
                visited[ny][nx] = 1;
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    string str;

    maps.assign(n, vector<int>(n, 0));
    visited.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        cin >> str;
        
        for (int j = 0; j < n; j++) {
            maps[i][j] = (str[j] == '1') ? 1 : 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (maps[i][j] && !visited[i][j]) {
                cnt = 1;
                visited[i][j] = 1;
                dfs(j, i);
                groups.push_back(cnt);
            }
        }
    }

    sort(groups.begin(), groups.end());
    
    cout << groups.size() << '\n';
    
    for (int i = 0; i < groups.size(); i++) {
        cout << groups[i] << '\n';
    }

    return 0;
}