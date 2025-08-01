// 민규가 카드 구매하기 1에서 돈을 너무 많이 써버림
// 그래서 이버너에는 최소로 지불할거임

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> cards(n + 1, 0);
    vector<int> dp(n + 1, 1e9); 

    for (int i = 1; i <= n; i++) {
        cin >> cards[i];
    }

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            // 카드를 i개 구매했을 때의 최소 비용
            dp[i] = min(dp[i], dp[i - j] + cards[j]);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
