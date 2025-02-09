#include <iostream>

using namespace std;

int n,  neg= 0, pos = 0, zero = 0;
int paper[2187][2187];

void cut(int y, int x, int size) {
    int num = paper[y][x];
    bool isSame = true;

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (num != paper[i][j]) {
                isSame = false;
                break;
            }
        }
        if (!isSame) break;
    }

    if (isSame) {
        if (num == 0) zero++;
        if (num == 1) pos++;
        if (num == -1) neg++;
    } else {
        cut(y, x, size / 3);

        cut(y, x + size / 3, size / 3);
        cut(y, x + size / 3 + size / 3, size / 3);

        cut(y + size / 3, x, size / 3);
        cut(y + size / 3 + size / 3, x, size / 3);

        cut(y + size / 3, x + size / 3, size / 3);
        cut(y + size / 3 + size / 3, x + size / 3 + size / 3, size / 3);
        cut(y + size / 3, x + size / 3 + size / 3, size / 3);
        cut(y + size / 3 + size / 3, x + size / 3, size / 3);
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    cut(0, 0, n);
    cout << neg << '\n' << zero << '\n' << pos << '\n';

    return 0;
}