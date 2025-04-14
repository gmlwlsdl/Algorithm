#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> family;
vector<bool> visited;
vector<int> dist;

void bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    while (!q.empty()) {
        int qs = q.front();
        q.pop();

        for (auto next:family[qs]) {
            if (!visited[next]) {
                visited[next] = true;
                dist[next] = dist[qs] + 1;
                if (next == end) return;
                q.push(next);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; // 사람 수
    cin >> n;

    int p1, p2; // 촌수를 구해야 하는 사ㅁ 수
    cin >> p1 >> p2;

    int m; // 관계의 개수
    cin >> m;

    family.resize(n + 1);
    visited.resize(n + 1, false);
    dist.resize(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        family[a].push_back(b);
        family[b].push_back(a);
    }

    bfs(p1, p2);

    if (dist[p2] == -1) cout << -1 << '\n';
    else cout << dist[p2] << '\n';

    return 0;
}

// 두 사람 사이의 최소 촌수를 구해야 하므로 BFS를 이용하자
// 그래프를 표현하는 방법은 여러 개가 있음
// 1. graph[x][y] = 1 -> 인접 행렬
// 2. graph[x].push_back(y) -> 인접 리스트