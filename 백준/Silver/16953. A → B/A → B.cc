#include <iostream>
#include <queue>

using namespace std;

long long b;

void bfs(long long a) {
    // 숫자, 횟수
    queue<pair<long long, int>> q;
    q.push({a, 1});

    while(!q.empty()) {
        long long qx_num = q.front().first;
        int qx_cnt = q.front().second;

        q.pop();

        if (qx_num == b) {
            cout << qx_cnt << '\n';
            return;
        }
        
        if (qx_num < b) {
            q.push({qx_num * 2, qx_cnt + 1});
            q.push({(qx_num * 10) + 1, qx_cnt + 1});    
        }
    }

    cout << "-1" << '\n';
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cnt = 0;

    long long  a;
    cin >> a >> b;

    bfs(a);
       
    return 0;
}


// 정수 a를 b로 바꾸려고 함
// 2를 곱하고
// 1을 수의 가장 오른쪽에 추가
// 필요한 연산의 최솟값에 1을 더한 값을 출력
// 만들 수 없으면 -1 출력

// b가 2로 나뉘면 2로 나누고
// 안 나뉘면 1을 제거 후 2로 나누기