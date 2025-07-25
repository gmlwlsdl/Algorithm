// 수 3개로 연도를 나타냄
// 각각의 수는 지구, 태양, 달을 나타냄
// 지구 E, 태양 S, 달 M
// 모듈러 연산 이용하기

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int E, S, M;
    cin >> E >> S >> M;

    int year = 1;

    while (true) {
        if (((year - E) % 15 == 0) && 
        ((year - S) % 28 == 0) && 
        ((year - M) % 19 == 0)) {
            cout << year << '\n';
            break;
        }

        year++;
    }

    return 0;

}