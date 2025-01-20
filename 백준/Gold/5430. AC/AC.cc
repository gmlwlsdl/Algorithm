#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // 테스트 케이스 개수
    cin >> T;

    while (T--) {
        string p; // 수행할 함수
        int n;    // 배열 크기
        cin >> p >> n;

        string arr_input;
        cin >> arr_input;

        deque<int> dq;

        // 배열 입력을 deque에 저장
        if (n > 0) {
            string num;
            for (char c : arr_input) {
                if (isdigit(c)) { // 숫자로 변경이 가능하면 true, 아니면 false
                    num += c;
                } else if (c == ',' || c == ']') {
                    if (!num.empty()) {
                        dq.push_back(stoi(num)); // num을 정수로 변환해서 deque에 넣기
                        num.clear(); // 초기화
                    }
                }
            }
        }

        bool reversed = false; // 배열이 뒤집힌 상태인지 기록
        bool error = false;    // 에러 발생 여부

        // 함수 실행
        for (char cmd : p) {
            if (cmd == 'R') {
                reversed = !reversed; // 뒤집기 상태 토글
            } else if (cmd == 'D') {
                if (dq.empty()) {
                    error = true; // 배열이 비어 있으면 에러
                    break;
                }
                if (reversed) {
                    dq.pop_back(); // 뒤집힌 상태에서는 뒤에서 삭제
                } else {
                    dq.pop_front(); // 정방향 상태에서는 앞에서 삭제
                }
            }
        }

        // 출력
        if (error) {
            cout << "error\n";
        } else {
            cout << '[';
            if (!dq.empty()) {
                if (reversed) {
                    for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
                        if (it != dq.rbegin()) cout << ',';
                        cout << *it;
                    }
                } else {
                    for (auto it = dq.begin(); it != dq.end(); ++it) {
                        if (it != dq.begin()) cout << ',';
                        cout << *it;
                    }
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}