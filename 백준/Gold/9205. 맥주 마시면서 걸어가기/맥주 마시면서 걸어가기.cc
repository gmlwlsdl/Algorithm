// 50m 가려면 그 전에 맥주 1병을 마셔야 함
// 편의점에서 빈 병을 버리고 새 맥주 병을 살 수 있음
// 박스에 들어있는 맥주는 20병을 넘을 수 없음

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

vector<Point> points;
vector<bool> visited;

double distance(const Point& a, const Point& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}


void bfs(int n) {
    queue<int> q;
    q.push(0); // 집
    visited[0] = true;

    bool canReach = false;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == n + 1) {
            canReach = true;
            break;
        }

        for (int i = 0; i < n + 2; i++) {
            if (!visited[i] && distance(points[current], points[i]) <= 1000) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    cout << (canReach ? "happy" : "sad") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        points.clear();
        visited.clear();
        
        points.resize(n + 2);
        visited.resize(n + 2, false);

        for (int i = 0; i < n + 2; i++) {
            cin >> points[i].x >> points[i].y;
        } 

        bfs(n);
    }

    return 0;
}