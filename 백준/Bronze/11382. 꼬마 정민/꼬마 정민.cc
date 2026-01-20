#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num[3] = {0, };

    long long a, b, c, result = 0;
    cin >> a >> b >> c;

    num[0] = a;
    num[1] = b;
    num[2] = c;

    for (int i = 0; i < 3; i++) {
        result += num[i];
    }

    cout << result << '\n';

    return 0;
}