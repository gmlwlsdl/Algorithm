#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt = 0;
    cin >> n;

    string s;
    map<string, bool> m;
    
    for (int i = 0; i < n; i++) {
        cin >> s;

        if (s == "ENTER") {
            m.clear();
            continue;
        }

        // s가 없으면 true로 설정
        if (m.find(s) == m.end()) {
            m[s] = true;
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}