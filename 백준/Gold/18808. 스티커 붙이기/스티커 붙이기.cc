// 회전시키 않고 모눈종이에 떼냄
// 다른 스티커와 겹치지 않게
// 놑북 안 벗어나게
// 가장 위쪽 왼쪽부터
// 위치가 없다면 90도 회전 시키고 다시 시도
// 4번 다 돌렸는데도 안 된다면 못 붙임
// 노트북에서 몇 개의 칸이 채워졌는지 구하자

// 스티커 세로 가로
// 1이 모양

#include <iostream>
#include <vector>

using namespace std;

int n, m, k; // 노트북 크기, 스티커 개수
vector<vector<int>> paper;

// 스티커를 90도 회전시키는 함수
vector<vector<int>> rotate(vector<vector<int>> &sticker) {
    int row = sticker.size(), col = sticker[0].size();
    vector<vector<int>> rotated(col, vector<int>(row, 0));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            rotated[j][row - 1 - i] = sticker[i][j];
        }
    }

    return rotated;
}

// 스티커를 (x, y) 위치에 붙일 수 있는지 확인
bool canAttach(vector<vector<int>> &sticker, int x, int y) {
    int row = sticker.size(), col = sticker[0].size();

    if (x + row > n || y + col > m) {
        return false; // 범위 초과
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (sticker[i][j] == 1 && paper[x + i][y + j] == 1) {
                return false; // 겹치는 경우 불가능
            }
        }
    }
    return true;
}

// 스티커를 (x, y) 위치에 붙이는 함수
void attachSticker(vector<vector<int>> &sticker, int x, int y) {
    int row = sticker.size(), col = sticker[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (sticker[i][j] == 1) {
                paper[x + i][y + j] = 1;
            }
        }
    }
}

// 노트북에 스티커 붙이기 시도
bool tryAttach(vector<vector<int>> &sticker) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (canAttach(sticker, x, y)) {
                attachSticker(sticker, x, y);
                return true; // 스티커 붙이기 성공
            }
        }
    }
    return false; // 붙일 공간 없음
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // 세로 가로 스티커개수
    cin >> n >> m >> k;
    paper.assign(n, vector<int>(m, 0)); // 노트북 초기화

    while (k--) {
        int sticker_row, sticker_col; // 스티커 가로 세로
        cin >> sticker_row >> sticker_col;
        vector<vector<int>> sticker(sticker_row, vector<int>(sticker_col));

        for (int i = 0; i < sticker_row; i++) {
            for (int j = 0; j < sticker_col; j++) {
                cin >> sticker[i][j];
            }
        }

        // 0도, 90도, 180도, 270도 회전하며 스티커 붙이기 시도
        for (int rot = 0; rot < 4; rot++) {
            if (tryAttach(sticker)) break; // 붙였으면 종료
            sticker = rotate(sticker); // 90도 회전
        }
    }

    // 스티커가 붙은 칸 개수 세기
    int filled = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (paper[i][j] == 1) filled++;
        }
    }

    cout << filled << '\n';
    return 0;
}