// n+1일 되는 날에 퇴사할 거임
// 남은 n일 동안 최대한 많은 상담할 거임
// t는 시간, p는 버는 돈

// 해당 날짜에 일을 할 수 있는가?
// 해당 날짜에 일을 하는 게 효율적인가?


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pair<int, int>> schedule(n + 1);
    vector<int> money(n + 2, 0);

    for (int i = 0; i < n ; i++) {
        int t, p;
        cin >> t >> p;

        schedule[i].first = t;
        schedule[i].second = p;
    }

    for (int i = n - 1; i >= 0; i--) {
        int t = schedule[i].first;
        int p = schedule[i].second;

        if (i + t <= n) { // 퇴사 전 날까지 일하는 거면 가능
            // 오늘 상담한 수익 + 다음 가능한 날부터의 수익 vs 내일 발생한 최대 수익
            money[i] = max(p + money[i + t], money[i + 1]); 
        } else {
            money[i] = money[i + 1];
        }
    }

    cout << money[0] << '\n';

    return 0;
}