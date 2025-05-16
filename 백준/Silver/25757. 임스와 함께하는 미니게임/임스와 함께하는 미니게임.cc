// 이미 게임한 사람이랑은 안 함
// 윷놀이 Y, 그림 찾기 F, 원카드 O

#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	char c;
	set<string> s;

	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;

		s.insert(name);
	}

	if (c == 'Y') cout << s.size() << '\n';
	if (c == 'F') cout << s.size()/2 << '\n';
	if (c == 'O') cout << s.size()/3 << '\n';

	return 0;
}