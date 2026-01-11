#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, max_value = 0;
int dx[4] = {0, 0, -1, 1}; // 상 하 좌 우
int dy[4] = {-1, 1, 0, 0}; // 상 하 좌 우

void check(vector<vector<char>> bomboni) {
    int cnt = 1;

    for (int i = 0; i < n; i++) {
        cnt = 1;

        for (int j = 1; j < n; j++) {
            if (bomboni[i][j] == bomboni[i][j-1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            max_value = max(max_value, cnt);
        }
    }

    for (int j = 0; j < n; j++) {
        cnt = 1;
        
        for (int i = 1; i < n; i++) {
            if (bomboni[i][j] == bomboni[i-1][j]) {
                cnt++;
            } else {
                cnt = 1;
            }
            max_value = max(max_value, cnt);
        }
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<vector<char>> bomboni;
    bomboni.assign(n, vector<char>(n, '-'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> bomboni[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int r = 0; r < 4; r++) {
                if (i + dx[r] >= 0 && i + dx[r] < n && j + dy[r] >= 0 && j + dy[r] < n) {
                    swap(bomboni[i][j], bomboni[i + dx[r]][j + dy[r]]);
                    check(bomboni);
                    swap(bomboni[i + dx[r]][j + dy[r]], bomboni[i][j]);
                }
            }  
        }
    }

    cout << max_value << '\n';

    return 0;
}