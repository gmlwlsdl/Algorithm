#include <iostream>

using namespace std;

int z(int n, int r, int c) {
    if (n == 0) {
        return 0;
    }
    int half = 1 << (n-1); // 2의 n-1승

    if (r < half && c < half) {
        return z(n-1, r, c);
    }

    if (r < half && c >= half) {
        return half*half + z(n-1, r, c-half);
    }

    if (r >= half && c < half) {
        return 2*half*half + z(n-1, r-half, c);
    }

    return 3*half*half + z(n-1, r-half, c-half);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, r, c;

    cin >> n >> r >> c;

    cout << z(n, r, c) << '\n';
}