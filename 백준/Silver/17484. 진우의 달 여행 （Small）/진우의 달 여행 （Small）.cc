// 지구와 달 사이의 공간
// dp로 하기에는
// 2 <= n, m <= 6이므로 완전 탐색도 가능할 거 같음

#include <iostream>

using namespace std;

int n, m;
int map[7][7];
int ans = 999999999;

int dx[3] = { -1, 0, 1 };

int move(int y, int x, int last) {
	if (y == n)	return 0;

	int tmp = 999999999;
    
	for (int i = 0; i < 3; i++) {
		if (x + dx[i] >= 0 && x + dx[i] < m && i != last)
			tmp = min(tmp, move(y + 1, x + dx[i], i) + map[y][x]);
	}

	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < m; i++)
		ans = min(ans, move(0, i, -1));

	cout << ans << '\n';
	
	return 0;
}