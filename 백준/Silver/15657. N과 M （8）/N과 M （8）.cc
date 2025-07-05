#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> input;         // 중복 제거된 입력값
vector<int> result;
vector<bool> visited;

void func(int depth, int start) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i];
			if (i != (m-1)) cout << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < input.size(); i++) {
        // if (!visited[i]) {
            visited[i] = true;
            result[depth] = input[i];
            func(depth + 1, i);
            visited[i] = false;
        // }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }

    sort(temp.begin(), temp.end());

	// 중복 제거
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    input = temp;

    result.resize(m);
    visited.resize(input.size(), false);

    func(0, 0);
    return 0;
}