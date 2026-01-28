#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt = 0;
    cin >> n;

    int alphabet[26];

    for (int j = 0; j < n; j++) {
        fill_n(alphabet, 26, -1);
        
        string s;
        cin >> s;

        bool flag = true;

        for (int i = 0; i < s.length(); i++) {
            if (alphabet[s.at(i) - 97] == -1) alphabet[s.at(i) - 97] = i;
            else {
                if (alphabet[s.at(i) - 97] == (i - 1)) alphabet[s.at(i) - 97] = i;
                else {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) cnt++;
    }

    cout << cnt << '\n';
    
    return 0;
}