// A의 크기 N과 M이 주어짐
// N개의 줄에 원소 M개
// 행렬 B의 크기 M과 K
// 원소 K가 차례대로
// N과 M, 그리고 K는 100보다 작거나 같고
// 원소는 절댓값이 100보다 작거나 같은 정숴

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a;
    a.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for  (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }    

    int k;
    cin >> m >> k;

    vector<vector<int>> b;
    b.assign(m, vector<int>(k, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> b[i][j];
        }
    }

    vector<vector<int>> result(n, vector<int>(k, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int k = 0; k < m; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
            cout << result[i][j];
            if (j != k-1) cout << ' ';
        }
        cout << "\n";
    }

    return 0;
}