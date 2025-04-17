#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> dp(n+1, 0);
    vector<int> wine(n+1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> wine[i];
    }

    dp[1] = wine[1];
    if (n >= 2) dp[2] = wine[1] + wine[2];

    for (int i = 3; i <= n; i++) {
        int temp = max(dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i]);
        dp[i] = max(temp, dp[i-1]);
    }

    cout << dp[n] << '\n';
   
    return 0;
}


// 3잔을 동시에 마실 수는 없음
// 1잔 마시고 다시 내려둠
// 최대로 많이 마셔야 함