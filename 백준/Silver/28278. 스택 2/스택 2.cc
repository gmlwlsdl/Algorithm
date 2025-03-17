#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    bool check = false;
    cin >> t;

    stack<int> st;

    while (t--) {
        int op;
        cin >> op;

        if (op == 1) {
            int num;
            cin >> num;
            check = true;
            st.push(num);
        }

        if (op == 2) {
            if (check) {
                cout << st.top() << '\n';
                st.pop();
                if (st.empty()) {
                    check = false;
                }
            } else {
                cout << "-1" << '\n';
            }
        }

        if (op == 3) {
            cout << st.size() << '\n';
        }

        if (op == 4) {
            if (st.empty()) {
                cout << 1 << '\n';
                check = false;
            }
            else cout << "0" << '\n';
        }

        if (op == 5) {
            if (check) {
                cout << st.top() << '\n';
            } else {
                cout << "-1" << '\n';
            }
        }
    }

    return 0;
}

// 1 X> 정수 x를 스택에 넣음
// 2 > 스택에 정수가 있으면 맨 위를 빼고 출력, 없으면 -1 출력
// 3 > 스택에 들어있는 정수의 개수 출력
// 4 > 스택이 비어있으면 1, 아니면 0
// 5 > 정수가 있으면 맨 위의 거 출력, 없으면 -1