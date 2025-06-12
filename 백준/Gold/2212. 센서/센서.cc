// n개의 센서를 설치함
// 고속도로에 최대 k개의 집중국을 세울 수 있음
// n개의 센서는 적어도 하나의 집중국과 통신하기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, len = 0;

    cin >> n >> k;

    vector<int> v(n);
    vector<int> diff(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 1; i < n; i++) {
        diff[i-1] = v[i] - v[i-1];
    }

    sort(diff.begin(), diff.end());

    for (int i = 0; i < n - k + 1; i++) {
        len += diff[i];
    }

    cout << len << '\n';

    return 0;
}