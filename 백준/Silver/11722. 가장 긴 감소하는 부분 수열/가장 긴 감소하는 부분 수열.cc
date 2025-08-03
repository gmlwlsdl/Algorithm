// 수열 A
// 감소하는 부분수열의 길이

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> seq(n + 1, 0);
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;

        for (int j = 1; j <= i; j++) {
            if (seq[i] < seq[j] && dp[j] + 1 > dp[i]) {
                // i번째 인덱스까지의 "감소하는 부분 수열"의 최대 길이
                dp[i] = dp[j] + 1;
            }
        }

    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}