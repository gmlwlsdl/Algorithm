#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> cards(n + 1, 0);
    vector<int> dp(n + 1, 0); 

    for (int i = 1; i <= n; i++) {
        cin >> cards[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            // 카드를 i개 구매했을 때의 최대 비용
            dp[i] = max(dp[i], dp[i - j] + cards[j]);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
