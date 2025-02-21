// N * N칸인 지도
// (r, c) 행 열
// 주사위는 (x, y)에 위치
// 이동한 칸에 적힌 수가 0 -> 주사위 바닥면의 수를 칸에 복사
// 0이 아닌 경우 -> 칸에 적힌 수를 주사위 바닥면으로 복사
// 주사위가 이동할 대마다 상단에 쓰여있는 값을 구하자
// 지도세로 지도가로 주사위x 주사위y 명령개수
// 동1 서2 남4 북3
// 지도를 벗어나면 출력 x 명령 무시

#include <iostream>
#include <vector>

using namespace std;

int n, m, x, y, k;
vector<vector<int>> board;
vector<int> dice(6, 0);  // 위 아래 동 서 북 남
int dx[4] = {0, 0, -1, 1}; // 동서북남
int dy[4] = {1, -1, 0, 0};

void move(int dir) {
    vector<int> temp = dice; // 현재 상태 복사

    if (dir == 0) { // 동
        dice[0] = temp[2];  // 위 -> 동
        dice[1] = temp[3];  // 아래 -> 서
        dice[2] = temp[1];  // 동 -> 아래
        dice[3] = temp[0];  // 서 -> 위
    }
    else if (dir == 1) { // 서
        dice[0] = temp[3];  // 위 ← 서
        dice[1] = temp[2];  // 아래 ← 동
        dice[2] = temp[0];  // 동 ← 위
        dice[3] = temp[1];  // 서 ← 아래
    }
    else if (dir == 2) { // 북
        dice[0] = temp[4];  
        dice[1] = temp[5];  
        dice[4] = temp[1];  
        dice[5] = temp[0];  
    }
    else if (dir == 3) { // 남
        dice[0] = temp[5];  
        dice[1] = temp[4];  
        dice[4] = temp[0];  
        dice[5] = temp[1];  
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x >> y >> k;
    board.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < k; i++) {
        int dir;
        cin >> dir;
        dir -= 1;  // 1,2,3,4 -> 0,1,2,3

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
            continue; 
        }

        x = nx;
        y = ny;
        move(dir); 

        if (board[x][y] == 0) {
            board[x][y] = dice[1];  // 바닥면 값 복사
        } else {
            dice[1] = board[x][y];  // 지도 값 주사위로 복사
            board[x][y] = 0;
        }

        cout << dice[0] << '\n';  
    }

    return 0;
}