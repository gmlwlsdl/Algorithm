#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare() {
    int a, b;
    
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> stock;

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;

            if (i == (n - 1)) {
                stock.push_back({val, val});
            } else {
                stock.push_back({val, 0});
            }
        }

        int max = stock[n - 1].second;
        for (int i = (n - 2); i >= 0; i--) {
            if (max < stock[i].first) {
                max = stock[i].first;
            }

            stock[i].second = max;
        }

        long long total = 0;
        for (int i = 0; i < (n - 1); i++) {
            int cur_val = stock[i].first;
            int cur_max = stock[i].second;


            if (cur_val < cur_max) {
                total += (cur_max - cur_val);
            }
        }

        cout << total << '\n';
    }

    return 0;
}