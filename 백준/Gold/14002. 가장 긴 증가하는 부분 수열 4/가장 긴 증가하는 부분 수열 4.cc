// 수열 A
// 가장 긴 증가하는 부분 수열

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
    vector<int> dp(n + 1, 1); // seq의 n번째 인덱스에서 가능한 가장 긴 증가하는 부분 수열의 길이, 각자 자기 자신을 가질 수 있으므로 1로 초기화
    vector<int> prev(n + 1, -1); // 뭐 때문에 lis가 성립했는지 추적하기 위함. 인덱스를 저장
    vector<int> lis; // 가장 긴 증가하는 부분 수열 저장

    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
    }

    int maxLen = 1;
    int lastIdx = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (seq[j] < seq[i]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j; // i는 j에 의해 lis를 만족하므로 j를 저장
                }
            }
        }
        
        if (dp[i] >= maxLen) {
            maxLen = dp[i];
            lastIdx = i; // 현재 i가 가장 긴 증가하는 부분 수열이므로 i를 저장
        }
    }

    for (int i = lastIdx; i != -1; i = prev[i]) {
        lis.push_back(seq[i]);
    }
    reverse(lis.begin(), lis.end());

    cout << lis.size() << '\n';
    for (int i = 0; i < lis.size(); i++) {
        cout << lis[i] << (i == lis.size() - 1 ? '\n' : ' ');
    }

    return 0;
}
