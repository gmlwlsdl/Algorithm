#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, length;
    cin >> n;
    length = pow(n, 2);

    vector<int> v(length, 0);

    for (int i = 0; i < length; i++) {
       cin >> v[i];
    }

    sort(v.begin(), v.end());

    cout << v[length - n] << '\n';

    return 0;
}