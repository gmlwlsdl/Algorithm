#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, idx;
    cin >> n >> k;

    if (n == 1) {
        cout << '1' << '\n';
    } else {
        vector<vector<int>> v(n, vector<int>(4, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> v[i][j];
            }
            if (v[i][0] == k) {
                idx = i;
            }
        }

        int cnt = 1;

        for (int i = 0; i < n; i++) {
            if (v[idx][1] == v[i][1]) {
                if (v[idx][2] == v[i][2]) {
                    if (v[idx][3] == v[i][3]) {
                        continue;
                    } else if (v[idx][3] < v[i][3]) {
                    cnt++;
                    }
                } else if (v[idx][2] < v[i][2]) {
                    cnt++;
                }
            } if (v[idx][1] < v[i][1]) {
                cnt++;
            } 
        }

        cout << cnt << '\n';
    }

    return 0;
}