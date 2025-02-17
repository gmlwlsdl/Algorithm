#include <iostream>

using namespace std;

int n, s, arr[30], cnt = 0;

void sequence(int idx, int sum) {
    if (idx == n) { // 모든 원소 확인
        if (sum == s) { // 원하는 합이 있으면 카운트 증가
            cnt++;
        }
        return;
    }

    sequence(idx + 1, sum + arr[idx]); // 현재 원소 포함
    sequence(idx + 1, sum); // 현재 원소 포함 X
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sequence(0,0);

    if (s == 0) {
        cnt--; // 공집한 제외
    }

    cout << cnt << '\n';
}