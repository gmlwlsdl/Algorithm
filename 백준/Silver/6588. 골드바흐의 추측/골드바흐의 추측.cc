// 6이상의 짝수를 a + b로 표현한다.
// 이때 a, b는 모두 소수이며,  b - a가 최대인 경우로 표기한다.
#include <iostream>
#include <vector>
#include <cmath>
#define MAX_SIZE 1000001

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<int> v(MAX_SIZE, 0);

    for (int i = 2; i <= MAX_SIZE; i++) {
        v[i] = i;
    }

    for (int i = 2; i <= sqrt(MAX_SIZE); i++) {
        for (int j = i * 2; j <= MAX_SIZE; j += i) {
            v[j] = 0;
        }
    }

    while (1) {
        cin >> n;

        if (!n) {
            break;
        }

        for (int i = (n - 1); i >= (n / 2); i--) {
            if (v[n - i]) {
                if (v[i] + v[n - i] == n) {
                    cout << n << " = " << v[n - i] << " + " << v[i] << '\n';
                    break;
                }
            }

            if (i == (n / 2)) {
                cout << "Goldbach's conjecture is wrong." << '\n';
            }
        }
    }

    return 0;
}