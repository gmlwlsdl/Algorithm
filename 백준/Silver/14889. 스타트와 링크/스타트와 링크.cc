// 팀은 2개, 팀원은 2/n명
// 팀원이 i, j일 때 팀의 능력치는 s[i][j] + s[j][i]
// 2개의 팀의 능력치 차이가 최대한 작을 때의 능력치 차이를 구하라

#include <iostream>
#include <vector>
#include <bit>

using namespace std;

vector<vector<int>> s;

int calc_stat(vector<int> &team) {
    int p1, p2, sum = 0;

    for (int i = 0; i < team.size(); i++) {
        for (int j = i + 1; j < team.size(); j++) {
            p1 = team[i];
            p2 = team[j];
            sum += s[p1][p2] + s[p2][p1];
        }
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    s.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }

    int min_value = 1e4;

    for (unsigned mask = 0; mask < (1 << n); mask++) {
        if (popcount(mask) == n / 2) {
            vector<int> start_team;
            vector<int> link_team;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    start_team.push_back(i);
                } else {
                    link_team.push_back(i);
                }
            }

            int start_stat = calc_stat(start_team);
            int link_stat = calc_stat(link_team);

            min_value = min(min_value, abs(start_stat - link_stat));
        }
    }

    cout << min_value << '\n';

    return 0;
}