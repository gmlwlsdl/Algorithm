// 서로 다른 L개의
// 최소 한 개의 a e i o u
// 최소 두 개의 자음
// 사전순

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int L, C;
vector<string> res;

void des(vector<string> alp, string sum, int cnt) {
	if (sum.length() == L) { // 만든 암호의 길이가 L이면
		res.push_back(sum); // 결과에 추가하고
		return; // 종료
	}
	if (cnt < C) {
		des(alp, sum + alp[cnt], cnt + 1); // 현재 알파벳 선택 o
		des(alp, sum, cnt + 1); // 현재 알파벳 선택 x
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> C;

	vector<string> alp;
	for (int i = 0; i < C; i++) {
		string ch;
		cin >> ch;
		alp.push_back(ch);
	}

	sort(alp.begin(), alp.end()); // 사전순 정렬

	des(alp, "", 0);
	
	for (int i = 0; i < res.size(); i++) {
		int mo=0;
		int ja = 0;

        // 조건에 만족하는 것만 출력
		for (int j = 0; j < res[i].length(); j++) {
			if (res[i][j] == 'a' || res[i][j] == 'e' || res[i][j] == 'i' || res[i][j] == 'o' || res[i][j] == 'u') mo++;
			else ja++;

			if (mo >= 1 && ja >= 2) {
				cout << res[i] << "\n";
				break;
			}
		}
	}

	return 0;
}
