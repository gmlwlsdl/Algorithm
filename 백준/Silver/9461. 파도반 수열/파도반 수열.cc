// t개의 테스트케이스에서
// 나선으로 추가되는 삼각형에서
// n번째 삼각형의 변의 길이를 구하자

#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t, n;
    cin >> t;
    
    vector<long long> dp(101, 0);
    dp[1] = dp[2] = dp[3] = 1;

    for (int i = 4; i <= 100; i++) {
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}