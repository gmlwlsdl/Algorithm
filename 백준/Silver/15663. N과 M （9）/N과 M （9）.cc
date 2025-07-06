#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
vector<int> input;
vector<int> result;
vector<bool> visited;
set<vector<int>> answer;

void func(int depth) {
    if (depth == m) {
        answer.insert(result); // 중복 수열 제거를 위해 set 사용
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            result[depth] = input[i];
            func(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    input.resize(n);
    visited.resize(n);
    result.resize(m);

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    sort(input.begin(), input.end()); // 사전순 출력을 위한 정렬

    func(0);

    for (const auto& seq : answer) {
        for (int i = 0; i < seq.size(); i++) {
            cout << seq[i];
            if (i != seq.size() - 1) cout << ' '; 
        }
        cout << '\n';
    }

    return 0;
}