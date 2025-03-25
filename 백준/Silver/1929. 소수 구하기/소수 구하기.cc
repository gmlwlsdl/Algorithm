#include <iostream>

using namespace std;

int arr[1000001];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int m, n;
    cin >> m >> n;

    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (arr[i] == 1) continue;

        // i의 배수를 검사하기 때문에 j ++ i
        for (int j = i * 2; j <= n; j += i) {
            arr[j] = 1;
        }
    }

    for (int i = m; i <= n; i++) {
        if (!arr[i]) cout << i << '\n';
    }

    return 0;
}
