// n가지 종류의 동전이 있다.
// 합해서 k원이 되도록 하자
// 동전의 개수가 최소가 되어야 함
// 사용 가능한 동전의 최소 개수를 구하자

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

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

    vector<int> dp(k + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int cur = v[i]; // 현재 금액

        for (int j = cur; j <= k; j++) {
            if (dp[j - cur] != INT_MAX) { // 오버플로우 방지
                dp[j] = min(dp[j], dp[j - cur] + 1); // cur원으로 j원 만드는데 들어가는 동전 개수를 더한 값이랑 그 이전에 들었던 개수 값이랑 비교하는 방식
            }
        }
    }

    if (dp[k] == INT_MAX) cout << "-1" << '\n';
    else cout << dp[k] << '\n';
    return 0;
}