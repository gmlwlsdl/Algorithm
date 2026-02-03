#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tc;
vector<int> selected;
vector<int> nums;

void dfs(int index, int cnt) {
    if (cnt == 6) {
        for (int i = 0; i < selected.size(); i++) {
            cout << selected[i];
            i < 5 ? cout << ' ' : cout << '\n';
        }
        return;
    }

    if (index == tc) {
        return;
    }

    selected.push_back(nums[index]);
    dfs(index + 1, cnt + 1);
    selected.pop_back();

    dfs(index + 1, cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0;

    while(1) {
        cin >> tc;

        nums.resize(tc);

        if (tc == 0) {
            return 0;
        }

        if (cnt > 0) {
            cout << '\n';
        }

        for (int i = 0; i < tc; i++) {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        dfs(0, 0);
        cnt += 1;
    }
}