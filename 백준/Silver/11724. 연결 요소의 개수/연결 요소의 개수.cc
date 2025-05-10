#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vec;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    
    // node에 연결된 node 갯수만큼 반복해서
    // 방문 안 했으면 계속 깊이 우선 탐색
    for (int i = 0; i < vec[node].size(); i++) {
        int curNode = vec[node][i];

        if (!visited[curNode]) {
            dfs(curNode);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cnt = 0;
    cin >> n >> m;

    vec.assign(n + 1, vector<int>(n + 1, 0));
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    for (int i = 1; i <= n; i++ ) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    
    cout << cnt << '\n';

    return 0;
}

// 1 - 2 - 5 - 1
// 3 - 4 - 6