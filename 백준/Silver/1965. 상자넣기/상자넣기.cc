// 정육면체가 일렬로 있음
// 앞 상자 크기 < 뒷 상자 크기 -> 앞에 있는 상자를 뒤에 있는 상자에 넣을 수 있음
// 한 번에 넣을 수 있는 최대의 상자 개수를 출력하자
// 가장 긴 증가하는 부분 수열!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    // i번째 숫자를 마지막으로 할 때 가지는 최대 수열 길이
    // 무조건 자기 자신은 가지므로 1로 초기화해야 함
    vector<int> v(n+1, 0);
    vector<int> dp(n+1, 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            // 뒷 상자가 앞 상자보다 크면
            // 이미 알고있는 넣을 수 있는 값 vs 이전에 넣을 수 있는 갯수 + 1(현재 숫자) 중 큰 값 저장
            if (v[i] > v[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}