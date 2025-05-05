#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[101] = {1, }; // 가장 긴 부분수열의 길이를 저장
    int n, maxValue = 0;
    cin >> n;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        int value = 0;

        for (int j = 0; j < i; j++) {
            if (v[i].second > v[j].second) value = max(value, dp[j]); 
        }

        dp[i] = value + 1;
    }

    for (int i = 0; i < n; i++) maxValue = max(maxValue, dp[i]);

    cout << n - maxValue << '\n';

    return 0;
}