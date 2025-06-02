// 스티커 2n개 구매
// 2행 n열로 배치
// 스티커 하나 떼면 상하좌우에 있는 스티커는 못 쓰게 됨
// 스티커 점수 합이 최대가 되도록 스티커를 떼어야 함
// 뗄 수 있는 스티커 점수의 최댓값을 구하자
// 타겟 위치를 1칸 뒤 대각선에서 접근하기 Or 2칸 뒤 대각선에서 접근하기 로 비교해서 최댓값으로 이동하면 된다!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    vector<vector <int>> v;
    vector<vector <int>> dp;
    
    while (t-- > 0) {
        int n;
        cin >> n;

        v.assign(2, vector<int>(n + 1, 0));
        dp.assign(2, vector<int>(n + 1, 0));
        
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> v[i][j];
            }
        }

        dp[0][0], dp[1][0] = 0;
        dp[0][1] = v[0][1], dp[1][1] = v[1][1];

        for (int i = 2; i <= n; i++) {
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + v[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + v[1][i];
        }

        cout << max(dp[0][n], dp[1][n]) << '\n';

    }

    return 0;
}