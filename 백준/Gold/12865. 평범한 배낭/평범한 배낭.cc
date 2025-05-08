#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> stuff(n);
    vector<int> dp(k + 1, 0);

    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;

        stuff[i] = {w, v};
    }

    for (int i = 0; i < n; i++) {
        int iw = stuff[i].first;  
        int iv = stuff[i].second; 

        // 넣을 수 있는 무게에서 현재 물건의 값까지 역순으로 내려가면서
        // dp 배열에 최댓값을 저장
        // dp = max(원래 dp, dp[넣을 수 있는 무게 - 현재 물건 무게] + 현재 물건 가치) 
        for (int j = k; j >= iw; j--) {
            dp[j] = max(dp[j], dp[j - iw] + iv);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}