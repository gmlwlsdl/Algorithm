#include <iostream>

using namespace std;

int sugar[5001];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, remain = 0, cnt = 0;
    cin >> n;

    while (n >= 0) {
        if (n % 5 == 0) {
            remain += n / 5;
            cout << remain << '\n';
            return 0;
        }

        n -= 3;
        remain++;
    }

    cout << "-1" << '\n';

    return 0;
}