#include <iostream>
#include <algorithm>

using namespace std;

int stairs[301]; // 각 계단의 값
int dp[301]; // 해당 계단까지의 최대값

int max (int a, int b) {
    return a > b ? a: b;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> stairs[i];
    }

    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = max(dp[0] + stairs[2], stairs[1] + stairs[2]);


    for (int j = 3; j < n; j++) {
        dp[j] = max(dp[j-2] + stairs[j], dp[j-3] + stairs[j-1] + stairs[j]);
    }

    cout << dp[n-1] << '\n';

    return 0;
}