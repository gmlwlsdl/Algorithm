#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, s = 0;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(b.begin(), b.end(), greater<>());

    for (int i = 0; i < n; i++) {
        s += a[i] * b[i];
    }

    cout << s << '\n';

    return 0;
}