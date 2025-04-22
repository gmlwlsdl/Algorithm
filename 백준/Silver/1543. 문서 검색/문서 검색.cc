// 세준이는 영어로만 이루어진 어떤 문서를 검색하는 함수를 만들거임
// 어떤 단어가 총 몇 번 등장하는지 셀거임
// 중복되어 세는 건 빼고 세야 함

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, compare;
    getline(cin, s);
    getline(cin, compare);

    int cnt = 0;
    int size = s.length();
    int c_size = compare.length();

    int j = 0;

    for (int i = 0; i <= size - c_size; ) {
        bool match = true;

        for (int j = 0; j < c_size; j++) {
            if (s[i + j] != compare[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            cnt++;
            i += c_size; 
        } else {
            i++; 
        }
    }

    cout << cnt << '\n';
    
    return 0;
}