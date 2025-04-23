// 1-3
// 1-4
// 2-3
// 3-4
// 4-5
//   - 4 - 5
// 1 - 3 - 2
// 모든 사람은 친구다
// 번호는 1부터 N까지
// push_back을 해야 함
// 링크드 리스트로 연결된 거니까
// start부터 n까지 몇 번 건너가야 하는지 계산을 계속 해야 함

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, cnt = 0;

vector<vector<int>> friends;
vector<int> dist;
vector<int> result;

void bfs(int start, int goal) {
    queue<pair<int, int>> q;
    vector<bool> visited(friends.size(), false);
    q.push({start, 1}); // 노드, 거리
    visited[start] = true;

    while (!q.empty()) {
        int qx = q.front().first;
        int q_cnt = q.front().second;

        q.pop();

        if (qx == goal) {
            result[start] += q_cnt;
            return;
        }

        for (int n:friends[qx]) {
            if (!visited[n]) {
                q.push({n, q_cnt+1});
                visited[n] = true;
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    friends.resize(n + 1);
    dist.resize(n + 1);
    result.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int p1, p2;
        cin >> p1 >> p2;

        friends[p1].push_back(p2);
        friends[p2].push_back(p1);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            bfs(i, j);
        }
    }

    int minPerson = 1;
    for (int i = 2; i <= n; i++) {
        if (result[i] < result[minPerson]) {
            minPerson = i;
        }
    }

    cout << minPerson << '\n';

    return 0;
}