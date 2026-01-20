#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(int y, int x, int l, vector<pair<int, int>> &stars) {
    int tp_y = y + l;
    int tp_x = x + l;
    int cnt = 0;

    for (auto &[ax, ay]: stars) {
        if (ax >= x && ax <= tp_x) {
            if (ay >= y && ay <= tp_y) {
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, l, k;
    cin >> n >> m >> l >> k;

    vector<pair<int, int>> stars;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        stars.push_back({x, y});
    }

    int cnt = 0;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int x = stars[i].first;
            int y = stars[j].second;

            cnt = max(cnt, calc(y, x, l, stars));
        }
    }

    cout << k - cnt << '\n';

    return 0;
}