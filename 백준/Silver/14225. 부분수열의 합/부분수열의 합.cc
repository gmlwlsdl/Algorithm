#include <iostream>

using namespace std;

int n, s, arr[30], cnt = 0, check[2000001];

void sequence(int idx, int sum) {
    check[sum] = true;

    if (idx == n) {
        return;
    } else {
        sequence(idx + 1, sum);
        sequence(idx + 1, sum + arr[idx]);
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sequence(0, 0);

    int j = 1;
    while (check[j] == true) {
        j++;
    }

    cout << j << '\n';

    return 0;
}