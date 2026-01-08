// f(x) = x의 약수들의 합
// g(a) = f(a보다 작거나 같은 모든 수)의 합

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;

    vector<long long> dp(1e6 + 1, 0);

    for (int i = 1; i < 1e6 + 1; i++) {
        for (int j = i; j < 1e6 + 1; j+=i) {
            dp[j] += i;
        }

        dp[i] += dp[i - 1];
    }
    
    while (t--) {
        cin >> n;

        cout << dp[n] << '\n';
    }

    return 0;
}