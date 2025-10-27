#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int n, int start, vector<vector<int>> graph, int answer) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    
    dist[1] = 0; // 1번 노드에서 1번 노드까지의 최단 거리는 0
    q.push(1);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (auto next: graph[cur]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    
    int max_dist = *max_element(dist.begin(), dist.end());
    
    for (auto d: dist) {
        if (d == max_dist) {
            answer++;
        }
    }
    
    return answer;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n + 1);
    
    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    answer = bfs(n, 1, graph, answer);
    
    return answer;
}