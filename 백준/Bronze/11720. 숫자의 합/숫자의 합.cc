#include <iostream>
#include <string.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int cnt, sum = 0;
    string numbers;

    cin >> cnt >> numbers;

    for (auto c:numbers) {
        sum += c - '0';
    }

    cout << sum << '\n';

    return 0;
}