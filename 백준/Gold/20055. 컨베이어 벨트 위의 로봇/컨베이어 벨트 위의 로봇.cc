#include <iostream>
#include <vector>

using namespace std;

int n, k, a_cnt = 0, cnt = 0;

void rotate(vector<int> &a, vector<bool> &robots) {
    int last_a = a[(2 * n - 1)];
    int last_r = robots[(2 * n - 1)];

    for (int i = (2 * n - 2); i >= 0; i--) {
        a[i + 1] = a[i];
        robots[i + 1] = robots[i];
    }
    a[0] = last_a;
    robots[0] = last_r;
}

void move(vector<int> &a, vector<bool> &robots) {
    for (int i = (n - 2); i >= 0; i--) { // 로봇은 n-1에서 무조건 내리기 때문에 위쪽 벨트에만 존재함
        if (robots[i] && !robots[i + 1] && a[i + 1] > 0) {
            a[i + 1]--;
            if (a[i + 1] == 0) a_cnt++;
            robots[i] = false;
            robots[i + 1] = true;
        }
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    vector<int> a(n * 2, 0);
    vector<bool> robots(n * 2, false);

    for (int i = 0; i < (n * 2); i++) {
        cin >> a[i];
    }
    
    while(1) {
        /* 1. 벨트 회전
        2. 기존 로봇 이동
        3. 내리는 위치에 로봇 제거
        4. 올리는 위치에 로봇 추가
        5. 내구도 0 개수 확인 -> 종료 */
        cnt++;
        rotate(a, robots);
        if (robots[(n - 1)]) robots[(n - 1)]= false;
        if (a_cnt >= k) break;
        
        move(a, robots);
        if (robots[(n - 1)]) robots[(n - 1)]= false;
        if (a_cnt >= k) break;

        if (a[0] > 0 && !robots[0]) {
            a[0]--;
            if (a[0] == 0) a_cnt++;
            robots[0] = true;
        }
        if (a_cnt >= k) break;
    }
    
    cout << cnt << '\n';

    return 0;
}