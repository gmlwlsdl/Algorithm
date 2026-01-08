// f(x) = x의 약수들의 합
// g(a) = f(a보다 작거나 같은 모든 수)의 합

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long sum = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        sum += (n / i) * i;
    }

    cout << sum << '\n';

    return 0;
}