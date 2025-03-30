#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> computers;
int n, k, cnt = 0;
bool visited[101] = {0, };
queue<int> q;

void bfs(int start) {
    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        start = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (computers[start][i] && computers[i][start] && !visited[i]) { // 컴퓨터간의 경로 있고, 아직 방문 안 한 경우
                q.push(i);
                visited[i] = 1;
                cnt++;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k; // 정점의 갯수, 간선의 갯수

    computers.assign(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < k; i++) {
        int start, end;
        cin >> start >> end;
        computers[start][end] = 1; // a <-> b 경로 있음
        computers[end][start] = 1;
    }

    bfs(1);
    cout << cnt << '\n';

    return 0;
}