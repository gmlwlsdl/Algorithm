// 두 단어의 구성이 같다 or 한 문자를 바꾸면 구성이 같아진다 -> 비슷한 단어

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int s_alphabet[26] = {0, };

    for (auto ss: s) {
        s_alphabet[ss - 65]++;
    }

    int cnt = 0;
    for (int i = 0; i < (n - 1); i++) {
        string word;
        cin >> word;

        int w_alphabet[26] = {0, };

        for (auto w: word) {
            w_alphabet[w - 65]++;
        }

        int total = 0, plus = 0, minus = 0;

        for (int j = 0; j < 26; j++) {
            int diff = s_alphabet[j] - w_alphabet[j];

            if (diff < 0) {
                minus += abs(diff);
            } else if (diff > 0) {
                plus += diff;
            }
        }

        if (plus < 2 && minus < 2) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}