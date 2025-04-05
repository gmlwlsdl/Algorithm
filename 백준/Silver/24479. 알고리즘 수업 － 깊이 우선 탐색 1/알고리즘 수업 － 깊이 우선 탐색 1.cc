#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> graphArr[100001];
bool visited[100001] = {false};
int result[100001] = {0};
int cnt = 0;

void dfs(int r) {
    if (visited[r]) {
        return;
    }

    visited[r] = true;
    cnt++; // 다음 턴으로
    result[r] = cnt;
    
    for (int i = 0; i < graphArr[r].size(); i++) { // 해당 정점에 연결된 간선의 수만큼?
        dfs(graphArr[r][i]); // 점정 r에 연결된 i 정점에서 새롭게 출발
    }

}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, r;
    cin >> n >> m >> r;

    // 입력 받고
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        graphArr[a].push_back(b);
        graphArr[b].push_back(a);
    }
    
    // 오름차순 정렬 하고
    for (int i = 1; i <= n; i++) {
        sort(graphArr[i].begin(), graphArr[i].end());
    }

    // r을 시작으로 dfs 돌리고
    dfs(r);

    // 출력
    for (int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}

// N개의 정점과 M개의 간선 > 무방향 그래프
// 1번부터 N번
// 모든 간선의 가중치는 1
// 정점 R에서 시작하여 DFS로 노드를 방문할 경우의 방문 순서는?
// 인접 정점은 오름차순으로 
// 정점 간선 시작