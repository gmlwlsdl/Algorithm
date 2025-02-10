#include <iostream>
#include <string>

using namespace std;

int n;
string video[64]; 

void zip(int y, int x, int size) {
    char num = video[y][x]; 
    bool isSame = true;

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (num != video[i][j]) { 
                isSame = false;
                break;
            }
        }
        if (!isSame) break;
    }

    if (isSame) {
        cout << num;
        return;
    } else {
        cout << '('; 
        zip(y, x, size / 2); 
        zip(y, x + size / 2, size / 2); 
        zip(y + size / 2, x, size / 2); 
        zip(y + size / 2, x + size / 2, size / 2); 
        cout << ')'; 
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> video[i]; 
    }

    zip(0, 0, n);

    return 0;
}