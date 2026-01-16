#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int visited[1001] = {0, };

void dfs(int start, vector<vector<int>> &vec) {
    visited[start] = 1;

    cout << start;

    if (vec[start].size() > 1) {
        sort(vec[start].begin(), vec[start].end());
    } 

    for (auto ns: vec[start]) {
        if (!visited[ns]) {
            cout << ' ';
            dfs(ns, vec);
        }
    }

    return;
}

void bfs(int start, vector<vector<int>> &vec) {
    visited[start] = 1;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int qx = q.front();
        q.pop();

        cout << qx << ' ';

        if (vec[qx].size() > 1) {
            sort(vec[qx].begin(), vec[qx].end());
        }

        for (auto nx: vec[qx]) {
            if (!visited[nx]) {
                visited[nx] = 1;
                q.push(nx);
            }
        }            
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> vec;
    vec.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        vec[from].push_back(to);
        vec[to].push_back(from);
    }

    dfs(v, vec);
    cout << '\n';
    fill(visited, visited + 1001, 0);
    bfs(v, vec);

    return 0;
}