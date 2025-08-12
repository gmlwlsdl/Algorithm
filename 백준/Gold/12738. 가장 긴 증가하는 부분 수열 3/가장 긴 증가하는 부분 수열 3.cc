// 수열 A
// 가장 긴 증가하는 부분 수열의 길이를 출력하자

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> seq(n + 1, 0);
    vector<ll> lis; 

    for (ll i = 0; i < n; i++) {
        cin >> seq[i];
    }

    for (ll i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), seq[i]);

        if (it == lis.end()) {
            lis.push_back(seq[i]);
        } else {
            *it = seq[i];
        }
    }

    cout << lis.size() << '\n';

    return 0;
}