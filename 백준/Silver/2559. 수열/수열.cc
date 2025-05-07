#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, sum = 0;
    cin >> n >> k;

    vector<int> arr(n);
    int dp[100001] = {0, };

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int initSum = 0;

    for (int i = 0; i < k; i++) {
        initSum += arr[i];
    }

    int maxValue = initSum;

    // 슬라이딩 윈도우
    for (int i = k; i < n; i++) {
        initSum = initSum - arr[i-k] + arr[i]; // 맨 앞에 더했던 거 빼고, 뒷 값 더하기
        maxValue = max(initSum, maxValue);
    }

    cout << maxValue << '\n';

    return 0;
}