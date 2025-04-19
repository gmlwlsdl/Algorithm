#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cnt = 0;
    long long a, b;

    cin >> a >> b;

    while(1) {
        // 같으면 종료
        if (a == b) break; 

        if ((a * 2) > b) {
            cout << "-1" << '\n';
            return 0;
        }

        if (b % 2 == 0) {
            b /= 2;
            cnt++;
        } else if (b % 10 == 1) {
            b = (b - 1) / 10;
            cnt++;
        } else {
            cout << "-1" << '\n';
            return 0;
        }
    }
    cout << cnt+1 << '\n';
       
    return 0;
}


// 정수 a를 b로 바꾸려고 함
// 2를 곱하고
// 1을 수의 가장 오른쪽에 추가
// 필요한 연산의 최솟값에 1을 더한 값을 출력
// 만들 수 없으면 -1 출력

// b가 2로 나뉘면 2로 나누고
// 안 나뉘면 1을 제거 후 2로 나누기