#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    map.assign(n+1, vector<int>(n+1));

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            int value;
            cin >> value;
            map[x][y] = value;
            map[x][y] = map[x-1][y] + map[x][y-1] + value - map[x-1][y-1];
        }
    }

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2, sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;

        sum = map[x2][y2] - map[x1-1][y2] - map[x2][y1-1] + map[x1-1][y1-1];

        cout << sum << '\n';
    }

    return 0;
}
