#include <iostream>

using namespace std;

int n, white = 0, blue = 0;
int paper[128][128];

void cut(int y, int x, int size) {
    int color = paper[y][x];
    bool isSame = true;

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (color != paper[i][j]) {
                isSame = false;
                break;
            }
        }
        if (!isSame) break;
    }

    if (isSame) {
        if (color == 0) white++;
        else blue++;
    } else {
        cut(y, x, size / 2);
        cut(y, x + size / 2, size / 2);
        cut(y + size / 2, x, size / 2);
        cut(y + size / 2, x + size / 2, size / 2);
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
    cout << white << '\n' << blue << '\n';

    return 0;
}