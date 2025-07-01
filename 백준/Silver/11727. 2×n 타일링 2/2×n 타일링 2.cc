// 2*n 직사각형을 1*2, 2*1, 2*2 로 채워야 

#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> dp(1000);
	dp[0] = 1;
	dp[1] = 3;

	for (int i = 2; i < n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	cout << dp[n-1] << '\n';

	return 0;
}