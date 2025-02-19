// 총 8개의 톱니를 가진 톱니바퀴 4개
// N극 또는 S극 중 하나를 나타냄
// 가장 왼쪽부터 1, 2, 3, 4
// 총 k번 회전
// 회전은 시계 or 반시계 1, -1
// 회전 시킬 톱니바퀴와 방향

// 총 4개의 톱니바퀴
// 회전할 톱니, 방향

// 12시 방향이 N극(0) 0점 , S극(1) 1점 합

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> gear(4, vector<int>(8)); // 4개의 톱니바퀴 (각 8개의 톱니)

// 시계 방향 회전
void rotateClockwise(vector<int>& g) {
    rotate(g.rbegin(), g.rbegin() + 1, g.rend()); // 오른쪽으로 쉬프트
}

// 반시계 방향 회전
void rotateCounterClockwise(vector<int>& g) {
    rotate(g.begin(), g.begin() + 1, g.end()); // 왼쪽으포 쉬픝
}

// 돌릴까말까
void turn(int gearNum, int dir) {
    gearNum--; // 1~4 -> 0~3 인덱스로 변환

    // 각 기어가 시계 방향으로 회전하는지 반시계 방향으로 회전하는지 (1이면 시계 -1이면 반시계)
    vector<int> rotateDir(4, 0);
    rotateDir[gearNum] = dir;

    // 왼쪽 기어 확인 (gearNum → 0 방향)
    for (int i = gearNum; i > 0; i--) {
        if (gear[i][6] != gear[i - 1][2]) { // 현재 기어의 왼쪽과 이전 기어의 오른쪽 극이 다르면 회전
            rotateDir[i - 1] = -rotateDir[i]; // 방향 반대로 설정
        } else {
            break; // 같은 극이라면 더 이상 영향을 주지 않음
        }
    }

    // 오른쪽 기어 확인 (gearNum → 3 방향)
    for (int i = gearNum; i < 3; i++) {
        if (gear[i][2] != gear[i + 1][6]) { // 현재 기어의 오른쪽과 다음 기어의 왼쪽 극이 다르면 회전
            rotateDir[i + 1] = -rotateDir[i]; // 방향 반대로 설정
        } else {
            break; // 같은 극이라면 더 이상 영향을 주지 않음
        }
    }

    // 기어 회전 적용
    for (int i = 0; i < 4; i++) {
        if (rotateDir[i] == 1) rotateClockwise(gear[i]);
        else if (rotateDir[i] == -1) rotateCounterClockwise(gear[i]);
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // 4개의 톱니바퀴 입력
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            gear[i][j] = s[j] - '0';
        }
    }

    int k;
    cin >> k; // 회전 횟수

    // k번 회전
    for (int i = 0; i < k; i++) {
        int gearNum, dir;
        cin >> gearNum >> dir;
        turn(gearNum, dir);
    }

    // 12시 방향이 S극(1)인 경우
    int score = 0;
    if (gear[0][0] == 1) score += 1;
    if (gear[1][0] == 1) score += 2;
    if (gear[2][0] == 1) score += 4;
    if (gear[3][0] == 1) score += 8;

    cout << score << '\n';

    return 0;
}