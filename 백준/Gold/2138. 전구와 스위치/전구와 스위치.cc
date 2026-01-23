#include <iostream>
#include <algorithm>

using namespace std;

int n;

void toggle(string &s, int idx) {
    if (idx == 0) {
        if (s[idx] == '0') s[idx] = '1';
        else s[idx] = '0';

        if (s[idx + 1] == '0') s[idx + 1] = '1';
        else s[idx + 1] = '0';
    } else if (idx == (n - 1)) {
        if (s[(n - 2)] == '0') s[(n - 2)] = '1';
        else s[(n - 2)] = '0';

        if (s[idx] == '0') s[idx] = '1';
        else s[idx] = '0';
    } else {
        if (s[idx - 1] == '0') s[idx - 1] = '1';
        else s[idx - 1] = '0';

        if (s[idx] == '0') s[idx] = '1';
        else s[idx] = '0';

        if (s[idx + 1] == '0') s[idx + 1] = '1';
        else s[idx + 1] = '0';
    }
}

int find(int cnt, string &current, string &answer) {
    for (int i = 1; i < n; i++) {
        if (current == answer) {
            return cnt;
        }

        if (current[i - 1] != answer[i - 1]) {
            toggle(current, i);
            cnt++;
        }
    }
    
    if (current == answer) {
            return cnt;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    string current, answer;
    cin >> current >> answer;

    // 0번째를 토글하고 시작
    string exp = current;
    toggle(exp, 0);
    int t_cnt = find(1, exp, answer);

    // 0번째를 토글하지 않고 시작
    int n_cnt = find(0, current, answer);
    
    if (t_cnt == n_cnt) {
        cout << t_cnt << '\n';
        return 0;
    }

    if (t_cnt == -1) {
        cout << n_cnt << '\n';
        return 0;
    }

    if (n_cnt == -1) {
        cout << t_cnt << '\n';
        return 0;
    }

    else cout << min(t_cnt, n_cnt) << '\n';

    return 0;
}