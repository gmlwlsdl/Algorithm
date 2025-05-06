#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int list[1001] = {0, };
    int dp[1001] = {1, };

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    for (int i = 0; i < n; i++) {
        int value = 0;

        for (int j = 0; j < i; j++) {
            if (list[i] > list[j]) value = max(value, dp[j]);
        }

        dp[i] = value + 1;
    }

    int maxValue = 0;

    for (int i = 0; i < n; i++) maxValue = max(maxValue, dp[i]);

    cout << maxValue << '\n';

    return 0;
}