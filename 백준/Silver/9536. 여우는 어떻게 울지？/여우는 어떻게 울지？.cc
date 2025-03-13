#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        string line; // 띄어쓰기 저장용
        getline(cin, line);

        string sound;
        getline(cin, sound);

        map<string, bool> animals;

        while (true) {
            string a, b, c;
            cin >> a >> b >> c;

            if (a == "what") {
                break;
            } else {
                animals[c] = true;
            }
        }

        string result;
        for (int i = 0; i < sound.length(); i++) {
            if (sound[i] == ' ') { // 공백이면
                if (!animals[result]) { 
                    cout << result << ' ';
                }
                result = "";
            } else {
                result += sound[i];
            }
        }
        if (!animals[result]) {
            cout << result << " ";
        } 
        cout << "\n";
    }

    return 0;
}

// 한신이는 고성능 녹음기로 무장
// 다른 동물들의 울음소리가 섞여 있음 -> 남은 잡음은 여우의 울음소리

// T 테스트케이스
// 소문자+공백