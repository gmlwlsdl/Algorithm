#include <iostream>
#include <vector>

using namespace std;

int n, m;

void copy(vector<vector<int>> &temp, vector<vector<int>> a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = a[i][j];
        }
    }
}

void print(vector<vector<int>> a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
            
            if (j == (m - 1)) {
                cout << '\n';
            } else {
                cout << " ";
            }
        }
    }
}

void calc(int op, vector<vector<int>> &a) {
    vector<vector<int>> temp(n, vector<int>(m, 0));
    copy (temp, a);

    if (op == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[n - i - 1][j] = temp[i][j];
            }
        }
    }

    if (op == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][m - j - 1] = temp[i][j];
            }
        }
    }

    if (op == 3 || op == 4) {
        vector<vector<int>> trans_temp(m, vector<int>(n, 0));
        
        if (op == 3) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    trans_temp[j][n - i - 1] = temp[i][j];
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    trans_temp[m - j - 1][i] = temp[i][j];
                }
            }
        }

        a = trans_temp;
        swap(n, m);
    }

    if (op == 5) {
        // 1 부분 구역
        for (int i = 0; i < (n / 2); i++) {
            for (int j = 0; j < (m / 2); j++) {
                a[i][j + (m / 2)] = temp[i][j];
            }
        }

        // 2 부분 구역
        for (int i = 0; i < (n / 2); i++) {
            for (int j = (m / 2); j < m; j++) {
                a[i + (n / 2)][j] = temp[i][j];
            }
        }

        // 3 부분 구역
        for (int i = (n / 2); i < n; i++) {
            for (int j = (m / 2); j < m; j++) {
                a[i][j - (m / 2)] = temp[i][j];
            }
        }

        // 4 부분 구역
        for (int i = (n / 2); i < n; i++) {
            for (int j = 0; j < (m / 2); j++) {
                a[i - (n / 2)][j] = temp[i][j];
            }
        }
    }

    if (op == 6) {
        for (int i = 0; i < (n / 2); i++) {
            for (int j = 0; j < (m / 2); j++) {
                a[i + (n / 2)][j] = temp[i][j];
            }
        }

        for (int i = 0; i < (n / 2); i++) {
            for (int j = (m / 2); j < m; j++) {
                a[i][j - (m / 2)] = temp[i][j];
            }
        }

        for (int i = (n / 2); i < n; i++) {
            for (int j = (m / 2); j < m; j++) {
                a[i - (n / 2)][j] = temp[i][j];
            }
        }

        for (int i = (n / 2); i < n; i++) {
            for (int j = 0; j < (m / 2); j++) {
                a[i][j + (m / 2)] = temp[i][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r;
    cin >> n >> m >> r;

    vector<vector<int>> a(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int op;
    for (int i = 0; i < r; i++) {
        cin >> op;

        calc(op, a);
    }
    
    print(a);

    return 0;
}