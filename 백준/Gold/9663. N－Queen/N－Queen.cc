#include <iostream>

using namespace std;

bool issued1[40];
bool issued2[40];
bool issued3[40];
int n, cnt = 0;

void queen(int cur) {
    if (cur == n) {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (issued1[i] || issued2[cur + i] || issued3[cur - i + n - 1]) continue;

        issued1[i] = true; // 행단위 선
        issued2[cur + i] = true; // 좌측 하단 -> 우측 상단 대각선
        issued3[cur - i + n - 1] = true; // 좌측 상단 -> 우측 하단 대각선

        queen(cur + 1);
        issued1[i] = false;
        issued2[cur + i] = false;
        issued3[cur - i + n - 1] = false;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    queen(0);
    cout << cnt << '\n';
}