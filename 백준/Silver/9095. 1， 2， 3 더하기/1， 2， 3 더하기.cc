// 정수 n을 1, 2, 3의 합으로 나타내는 방법의 수를 계산해야 함
// n은 11보다 작다

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    vector<int> dp(12, 0);

    dp[0] = 1, dp[1] = 2, dp[2] = 4;

    for (int i = 3; i <= 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    while (T--) {
        int n;
        cin >> n;

        cout << dp[n - 1] << '\n';
    }

    return 0;
}