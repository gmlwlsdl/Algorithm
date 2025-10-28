#include <string>
#include <vector>

using namespace std;

void dfs (int current, int n, vector<bool> &visited, vector<vector<int>> computers) {
    visited[current] = 1;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && computers[current][i]) {
            dfs(i, n, visited, computers);
        }
    }
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, visited, computers);
            answer++;
        }
    }
    
    return answer;
}