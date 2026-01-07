// 1, 11, 111, ... 울 n으로 나눴을 때 0이 되는 가장 작은 1의 배수 숫자
// 그 숫자의 자릿수 == 1의 갯수
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (cin >> n) {
        long long answer = 1;
        long long cnt = 1;

        while (answer % n != 0) {
            cnt++;
            answer = answer * 10 + 1;
            answer %= n; // A mod B == (A mod B) mod B
        }
        
        cout << cnt << '\n';
    }

    return 0;
}