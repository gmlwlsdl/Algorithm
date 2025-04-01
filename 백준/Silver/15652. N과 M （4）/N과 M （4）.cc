#include <iostream>
#include <map>

using namespace std;

int n, m; // n음 범위, m은 수열의 길이
int arr[9];
bool issued[9] = {false };

void func(int k, int start) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            // if (!issued[i]) {
                cout << arr[i] << " ";
            // }
        }
        cout << '\n';
        return ;
    }

    for (int i = start; i <= n; i++) {
        // if (!issued[i]) {
            issued[i] = true;
            arr[k] = i;
            func(k+1, i);
            issued[i] = false;
        // }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    func(0, 1);

    return 0;
}