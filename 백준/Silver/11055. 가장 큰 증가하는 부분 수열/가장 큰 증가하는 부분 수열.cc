// 수열 A
// 증가하는 부분 수열 중에서 합이 가장 큰 것을 구하자

#include <iostream>
#include <vector>

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

    int maxSum = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = seq[i];

        for (int j = 1; j < i; j++) {
            if (seq[j] < seq[i] && dp[i] < dp[j] + seq[i]) {
                // i번째 인덱스까지의 가장 큰 부분 수열의 합
                dp[i] = dp[j] + seq[i];
            }
        }

        if (maxSum < dp[i]) {
            maxSum = dp[i];
        }
    }

    cout << maxSum << "\n";

    return 0;
}
