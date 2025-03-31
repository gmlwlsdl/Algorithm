#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    map<string, bool> people_status; // 이름과 상태를 기록하는 map

    for (int i = 0; i < n; i++) {
        string name, status;
        cin >> name >> status;

        if (status == "enter") {
            people_status[name] = true;  // enter 상태 -> true
        } else if (status == "leave") {
            people_status[name] = false; // leave 상태 -> false
        }
    }

    // "enter" 상태인 사람만 출력
    for (auto it = people_status.rbegin(); it != people_status.rend(); ++it) {
        if (it->second) {  // 상태가 true인 경우
            cout << it->first << '\n';
        }
    }

    return 0;
}