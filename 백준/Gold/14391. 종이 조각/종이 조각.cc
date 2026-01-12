#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    char c;
    vector<vector<int>> v(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            v[i][j] = c - '0';
        }
    }

    int max_sum = 0;

    for (unsigned mask = 0; mask < (1 << n * m); mask++) {
        int total_sum = 0;

        for (int i = 0; i < n; i++) {
            int row_sum = 0;

            for (int j = 0; j < m; j++) {
                int cur = i * m + j;

                if (mask & (1 << cur)) { // 가로는 1로 가정
                    row_sum = row_sum * 10 + v[i][j];
                } else {
                    total_sum += row_sum;
                    row_sum = 0;
                }
            }

            total_sum += row_sum;
        }

        for (int i = 0; i < m; i++) {
            int col_sum = 0;

            for (int j = 0; j < n; j++) {
                int cur = j * m + i;

                if ((mask & (1 << cur)) == 0) { // 세로는 0으로 가정
                    col_sum = col_sum * 10 + v[j][i];
                } else {
                    total_sum += col_sum;
                    col_sum = 0;
                }
            }

            total_sum += col_sum;
        }

        max_sum = max(max_sum, total_sum);
    }

    cout << max_sum << '\n';

    return 0;
}