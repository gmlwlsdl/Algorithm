// 실력 차이가 많이 나도록 조를 짜야 한다.
// 우선 나이 순서대로 정렬하고
// 적당히 조를 짜자

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, minDP, maxDP;
    cin >> n;

    vector<int> v(n, 0);
    vector<int> dp(n+1, 0); // dp[i]는 i번째 사랆까지 조를 짰을 때의 최대값

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        minDP = v[i];
        maxDP = v[i];

        for (int j = i; j < n; j++) {
            minDP = min(minDP, v[j]);
            maxDP = max(maxDP, v[j]);

            dp[j + 1] = max(dp[j + 1], dp[i] + maxDP - minDP); // 현재 j+1의 최댓값 vs 이전 조의 최대값 + (현재까지 점수들에서 점수차 구한 값)
        }
    }

    cout << dp[n] << '\n';
    
    return 0;
}