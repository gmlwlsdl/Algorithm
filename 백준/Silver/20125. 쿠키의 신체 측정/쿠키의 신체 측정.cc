// 왼팔은 심장 바로 왼쪽
// 오른팔은 심장 바로 오른쪽
// 허리는 심장에서 아래쪽으로
// 왼다리는 허리 왼쪽 아래
// 오른다리는 허리 오른쪽 아래
// 심장 x좌표 y좌표 출력
// 왼팔 오른팔 허리 왼다리 오른다리 길이 출력하기

#include <iostream>
#include <vector>

using namespace std;

int n;

int left_arm(const vector<vector<char>> &body, int x, int y) {
    int length = 0;
    for (int i = x - 1; i >= 0; i--) {
        if (body[y][i] != '*') break;
        length++;
    }
    return length;
}

int right_arm(const vector<vector<char>> &body, int x, int y) {
    int length = 0;
    for (int i = x + 1; i < n; i++) {
        if (body[y][i] != '*') break;
        length++;
    }
    return length;
}

int weight(const vector<vector<char>> &body, int x, int y, int &out_y) {
    int length = 0;
    for (int i = y + 1; i < n; i++) {
        if (body[i][x] != '*') break;
        length++;
        out_y = i; // 다리 시작점의 y좌표 저장
    }
    return length;
}

int left_leg(const vector<vector<char>> &body, int x, int y) {
    int length = 0;
    for (int i = y + 1; i < n; i++) {
        if (body[i][x - 1] != '*') break;
        length++;
    }
    return length;
}

int right_leg(const vector<vector<char>> &body, int x, int y) {
    int length = 0;
    for (int i = y + 1; i < n; i++) {
        if (body[i][x + 1] != '*') break;
        length++;
    }
    return length;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    vector<vector<char>> body(n, vector<char>(n));
    
    int heart_x = -1, heart_y = -1;

    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> body[i][j];
            if (!found && body[i][j] == '*') {
                heart_y = i + 1; 
                heart_x = j;
                found = true;
            }
        }
    }

    cout << heart_y + 1 << ' ' << heart_x + 1 << '\n';

    int la = left_arm(body, heart_x, heart_y);
    int ra = right_arm(body, heart_x, heart_y);
    int waist_y;
    int wt = weight(body, heart_x, heart_y, waist_y);
    int ll = left_leg(body, heart_x, waist_y);
    int rl = right_leg(body, heart_x, waist_y);

    cout << la << ' ' << ra << ' ' << wt << ' ' << ll << ' ' << rl << '\n';

    return 0;
}