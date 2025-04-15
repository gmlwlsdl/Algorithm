#include <iostream>

using namespace std;

void calc(int top, int bottom) {
    for (int i = bottom; i > 0; i--) {
        if (top % i == 0 && bottom % i == 0) {
            top /= i;
            bottom /= i;
        } 
    }
    cout << top << "/" << bottom << '\n';
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, c;

    while (cin >> a >> b >> c) {
        calc((a * b), (c - b));
    }

    return 0;
}