// 받은 길이 - lis

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, idx;
    cin >> n;

    vector<int> seq(n + 1, 0);
    vector<int> lis; // 가장 긴 증가하는 부분 수열

    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
    }

    for (int i = 1; i <= n; i++) {
        // lis에서 seq[i] 이상인 첫 번째 원소를 찾음
        auto it = lower_bound(lis.begin(), lis.end(), seq[i]);

        if (it == lis.end()) { // 없으면 lis에 추가
            lis.push_back(seq[i]);
        } else { // 있으면 교체
            *it = seq[i];  
        }
    }

    cout << n - (int)lis.size() << '\n'; 

    return 0;
}
