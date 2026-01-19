#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
vector<char> consonants = {'b', 'c', 'd', 'f', 'g', 'h', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'x', 'z'};

bool rule1(string s) {
    for (auto a: s) {
        auto it = find(vowels.begin(), vowels.end(), a);

        if (it != vowels.end()) {
            return true;
        } else {
            continue;
        }
    }

    return false;
}

bool rule2(string s) {
    int v_cnt = 0, c_cnt = 0;

    bool vowel, consonant = false;
    for (auto a: s) {
        auto it = find(vowels.begin(), vowels.end(), a);

        if (it != vowels.end()) {
            if (vowel && v_cnt == 2) {
                return false;
            } else {
                consonant = false;
                c_cnt = 0;
                vowel = true;
                v_cnt++;
            }
        } else {
            if (consonant && c_cnt == 2) {
                return false;
            } else {
                vowel = false;
                v_cnt = 0;
                consonant = true;
                c_cnt++;                
            }
        }
    }

    return true;
}

bool rule3(string s) {
    char c = s[0];
    bool flag = false;

    for (int i = 0; i < s.length(); i++) {
        if (i != 0) {
            if (c == s[i]) {
                if (c == 'e' || c == 'o') flag = true;
                else flag = false;

                if (!flag) return flag;
            }

            c = s[i];
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        string s;
        cin >> s;

        if (s == "end") {
            break;
        }

        if (rule1(s) && rule2(s) && rule3(s)) {
            cout << "<" << s << ">" << " is acceptable." << '\n';
        } else {
            cout << "<" << s << ">" << " is not acceptable." << '\n';
        }
    }

    return 0;
}

