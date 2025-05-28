// 비어있는 공집합 S
// add x : x 추가 (이미 있으면 무시)
// remove x : x 제거 (이미 있으면 무시)
// check x : x가 있으면 1, 없으면 0
// toggle x : x가 있으면 제거, 없으면 추가
// add : s를 1~20 집합으로 변경
// empty : S를 공집합으로 바꾼다

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string op = "";
    int m, x;

    int s = 0;

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> op;

        if (op == "add") {
            cin >> x;
            s |= (1 << x); // or 연산을 통해서 추가
        } else if (op == "remove") {
            cin >> x;
            s &= ~(1 << x); // and 연산을 통해서 제거
        } else if (op == "check") {
            cin >> x;
            if (s & (1 << x)) cout << 1 << '\n'; // 있으면 
            else cout << 0 << '\n';
        } else if (op == "toggle") {
            cin >> x;
            if (s & (1 << x)) s &= ~( 1 << x ); // 있으면 제거
            else s |= (1 << x); // 없으면 추가
        } else if (op == "all") {
            s = (1 << 21) - 1;
        } else if (op == "empty") {
            s = 0;
        }
    }

    return 0;
}