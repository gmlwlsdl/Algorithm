#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool issued[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!issued[i]) {
            arr[k] = i;
            issued[i] = true;
            func(k+1);
            issued[i] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    func(0);
}