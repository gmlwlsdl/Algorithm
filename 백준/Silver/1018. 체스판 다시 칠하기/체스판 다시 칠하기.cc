#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<char>> chess; 

string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};

string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
};

int W(int x, int y) {
    int cnt = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chess[i + x][j + y] != WB[i][j]) cnt++;
        }
    }

    return cnt;
}

int B(int x, int y) {
    int cnt = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chess[i + x][j + y] != BW[i][j]) cnt++;
        }
    }

    return cnt;
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, minVal = 64;
    cin >> n >> m;

    chess.assign(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> chess[i][j];
        }
    }

    for (int i = 0; i + 8 <= n; i++) {
        for (int j = 0; j + 8 <= m; j++) {
            int current = min(W(i, j), B(i, j));
            if (current < minVal) minVal = current;
        }
    }

    cout << minVal << '\n';

    return 0;
}

// 검은색과 흰색이 번갈아서 칠해져 있어야 함
// 각 칸은 검은 or 흰 색
// 변을 공유하는 사각형은 다른 색으로 칠해져 있음
// 맨 윗 칸이 흰색인 경우, 검은색인 경우