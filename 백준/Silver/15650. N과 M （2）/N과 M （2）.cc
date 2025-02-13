#include <iostream>

using namespace std;

int n, m; // 숫자는 n까지 쓸 수 있고 m개의 배열 3 1
int arr[10];
bool issued[10];

void func(int num, int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = num; i <= n; i++) {
        if (!issued[i]) {
            arr[k] = i;
            issued[i] = true;
            func(i+1, k+1);
            issued[i] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    func(1, 0);
}