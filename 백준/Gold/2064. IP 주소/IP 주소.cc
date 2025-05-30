// ip 주소는 네 개의 바이트로 구성되어 있음
// 각각을 10진수로 나타냄. 사이에 점을 찍어서 표현
// 각 수는 0~255
// 각각의 바이트를 8자리 이진수로 나타내고
// 네 개 붙여놓은 32자리 이진수로 
// IP 네트워크는 기본적으로 2의 M승개의 컴퓨터가 할당됨

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string input, char dlim) {
    vector<string> result;
    stringstream s;
    string stringBuffer;
    
    s.str(input); // stringstream에 input 넣고

    // s에서 "."을 기준으로 잘라서 stringBuffer에 저장
    while (getline(s, stringBuffer, dlim)) {
        // 잘라낸 문자열을 vector에 저장
        result.push_back(stringBuffer);
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    // IP 입력받고
    vector<string> s(tc);

    for (int i = 0; i < tc; i++) {
        cin >> s[i];
    }

    // . 기준으로 나눠서 2차원 벡터에 int로 저장
    vector<vector<int>> v(tc);

    for (int i = 0; i < s.size(); i++) {
        // ex) s[0] = "192.168.0.1"

        vector<string> result = split(s[i], '.');
        // ex) result = ["192", "168", "0", "1"]

        for (int j = 0; j < result.size(); j++) {
            int t = stoi(result[j]); // 문자열을 정수고 변환하고
            v[i].push_back(t); // 벡터에 삽입
        }
        // ex) v[0] = {192, 168, 0, 1}

    }

    // 입력받은 주소가 1개일 경우
    if (v.size() == 1) {
        cout << s[0] << '\n' << "255.255.255.255";
        return 0;
    }

    // 네트워크의 크기 구하기

    // 1. 정렬해서 가장 큰 값, 작은 값 구하고
    sort(v.begin(), v.end());

    // 2. 각각의 주소값을 2진수로 변환해서 a[32], b[32]에 저장하고
    int vv = v.size() - 1;

    // ip = XXXX.XXXX.XXXX.XXXX
    // 각 자리의 바이트는 xxxx xxxx . xxxx xxxx . xxxx xxxx . xxxx xxxx 이므로
    int a[32], b[32]; // 가장 작은 IP(v[0]), 가장 큰 IP(v[vv])

    for (int i = 0; i < 4; i++) {
        int aa = 128, bb = 128;

        for (int j = 0; j < 8; j++) {
            if (v[0][i] >= aa) {
                // i에 8을 곱하는 이유는 각 자리당 8바이트이므로 다음 자리로 넘어가기 위함!
                a[j + i * 8] = 1;
                v[0][i] -= aa;
            } else {
                a[j + i * 8] = 0;
            }

            // 128 -> 64 -> ... -> 1
            aa /= 2;

            if (v[vv][i] >= bb) {
                b[j + i * 8] = 1;
                v[vv][i] -= bb;
            } else {
                b[j + i * 8] = 0;
            }

            // 128 -> 64 -> ... -> 1
            bb /= 2;
        }
    }

    // 3. 두 배열을 비교해서 값이 달라지는 첫 번째 인덱스를 구하기
    int index = 32;

    for (int i = 0; i < 32; i++) {
        if (a[i] != b[i]) {
            index = i;
            break;
        }
    }

    // 해당 인덱스만큼 1, 그 이후엔 0으로 구성된 배열 만들기
    int m[32];
    
    for (int i = index; i < 32; i++) {
        m[i] = 0;
    }

    for (int i = 0; i < index; i++) {
        m[i] = 1;
    }

    // 서브넷 마스크 값이 1이면 가장 작은 주소값, 아니면 0을 리턴
    // 이게 주소의 최솟값 (시작값)이다.
    int n[32];

    for (int i = 0; i < 32; i++) {
        if (m[i] == 1) {
            n[i] = a[i];
        } else {
            n[i] = 0;
        }
    }

    // 두 배열을 10진수로 변환
    int mt[4], nt[4];

    for (int i = 0; i < 4; i++) {
        int k = 0, kk = 0, t = 128;

        for (int j = 0; j < 8; j++) {
            if (m[j + i * 8] == 1) {
                k += t;
            }

            if (n[j + i * 8] == 1) {
                kk += t;
            }

            t /= 2;
        }

        mt[i] = k;
        nt[i] = kk;
    }

    // "."과 함께 출력
    for (int i = 0; i < 4; i++) {
        cout << nt[i];

        if (i != 3) {
            cout << '.';
        }
    }

    cout << '\n';

    for (int i = 0; i < 4; i++) {
        cout << mt[i];
        if (i != 3) {
            cout << '.';
        }
    }
}