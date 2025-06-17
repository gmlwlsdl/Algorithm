// n가지 종류의 동전이 있다.
// 합해서 k원이 되도록 하자
// 경우의 수를 구하자

#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> dp(k + 1, 0);
    dp[0] = 1; // 0원 만드는 경우의 수는 1개 아무것도 안 쓰기 밖에 없음

    for (int i = 0; i < n; i++) {
        int cur = v[i]; // 현재 금액

        for (int j = cur; j <= k; j++) {
            dp[j] += dp[j-cur]; // cur원으로 j원 만드는데 들어가는 비용을 더해가는 방식
        }
    }

    cout << dp[k] << '\n';
    return 0;
}