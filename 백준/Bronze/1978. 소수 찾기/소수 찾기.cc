#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int cnt, sum = 0;
    cin >> cnt;

    for (int i = 0; i < cnt; i++) {
        int num;
        cin >> num;

        bool isPrime = true;

        for (int j = 2; j < num; j++) {
            if (num % j == 0) {
                isPrime = false;
                break;
            } 
        }

        if (isPrime && num != 1) {
            sum++;
        }
    }

    cout << sum << '\n';
    
    return 0;
}