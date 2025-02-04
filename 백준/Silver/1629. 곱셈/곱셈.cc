#include <iostream>

using namespace std;

using ll = long long;

int POW(int a, int b, int m) {
    if (b == 1) {
        return a % m; // a가 m보다 클 수도 있음
    }

    ll value = POW(a, b/2, m);

    value = value * value % m;

    // 짝수인 경우
    if (b%2 == 0) {
        return value;
    }

    // 홀수인 경우에는 한 번 더 곱하고 나눠줘야야 함
    return value * a % m;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll a, b, c;

    cin >> a >> b >> c;

    cout << POW(a, b, c) << '\n';
}