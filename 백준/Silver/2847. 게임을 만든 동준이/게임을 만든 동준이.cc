// 플레이어 점수는 클리어한 점수의 합
// 쉬운 레벨이 어려운 레벨보다 많은 점수를 받는 경우가 있음
// 이런 경우를 없애야 함 1씩 점수를 줄이자

#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, cnt = 0;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = n - 2; i >= 0; i--) {
        if (v[i] >= v[i + 1]) {
            int new_val = v[i + 1] - 1; 
            cnt += v[i] - new_val;
            v[i] = new_val;
        }
    }

    cout << cnt << '\n';

    return 0;
} 