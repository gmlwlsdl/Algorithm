#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> v(n, 0);
    v[0] = 1;
    v[1] = 2;

    for (int i = 2; i < n; i++) {
        v[i] = (v[i - 1] + v[i - 2]) % 10007;
    }

    cout << v[n - 1] << '\n';

    return 0;
}