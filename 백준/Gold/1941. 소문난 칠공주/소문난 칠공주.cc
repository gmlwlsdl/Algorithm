#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {0, 0, -1, 1};  // 상하좌우
int dy[4] = {1, -1, 0, 0};
string student[5]; // 띄어쓰기 업으면 string으로 받아야 함
bool selected[5][5]; // 선택됐는지
int result = 0;
vector<pair<int, int>> positions;

void bfs(vector<pair<int, int>> &positions) {
    queue<pair<int, int>> q;
    bool visited[5][5] = {false};
    int cnt = 1, y_cnt = 0; 

    q.push(positions[0]); // 첫 번째 선택된 학생으로 시작
    visited[positions[0].first][positions[0].second] = true;

    for (auto pos : positions) {
        if (student[pos.first][pos.second] == 'Y') {
            y_cnt++; // Y가 몇 명이나 있는지 
        }
    }

    if (y_cnt > 3) return; // Y가 3명 초과면 종료

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (selected[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                cnt++;
            }
        }
    }

    if (cnt == 7) result++; // 7명이 인접하면 정답 증가
}

void backtrack(int index, int count, vector<pair<int, int>> &positions) {
    if (count == 7) { // 7명 선택 완료
        bfs(positions); // 인접해있는지 검사
        return;
    }

    for (int i = index; i < 25; i++) {
        int x = i / 5;
        int y = i % 5;
        
        selected[x][y] = true;
        positions.push_back({x, y});
        backtrack(i + 1, count + 1, positions);
        positions.pop_back();
        selected[x][y] = false;
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 5; i++) {
        cin >> student[i];
    }
    
    backtrack(0, 0, positions);

    cout << result << '\n';

    return 0;
}