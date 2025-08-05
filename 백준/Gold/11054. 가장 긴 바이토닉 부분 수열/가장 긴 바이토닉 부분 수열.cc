// 바이토닉 = 가장 긴 증가하는 부분 수열 길이 + 가장 긴 감소하는 부분 수열 길이 - 1

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
    vector<int> lis(n + 1, 1); // 가장 긴 증가하는 부분 수열
    vector<int> lds(n + 1, 1); // 가장 긴 감소하는 부분 수열

    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            // 증가하는 수열 길이
            if (seq[j] < seq[i] && lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            // 감소하는 수열 길이
            if (seq[j] < seq[i] && lds[i] < lds[j] + 1) {
                    lds[i] = lds[j] + 1;
            }
        }
    }

    int maxLen = 0;
    for (int i = 1; i <= n; i++) {
        maxLen = max(maxLen, lis[i] + lds[i] - 1);
    }
    
    cout << maxLen << '\n';

    return 0;
}
