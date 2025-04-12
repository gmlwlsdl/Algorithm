#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> sejong(n);
    multiset<int> yeongjae;

    for (int i = 0; i < n; i++) {
        cin >> sejong[i];
    }

    for (int i = 0; i < n; i++) {
        int money;
        cin >> money;
        yeongjae.insert(money);
    }

    vector<int> result;

    for (int i = 0; i < n; i++) {
        auto it = yeongjae.lower_bound(sejong[i]);
        if (it == yeongjae.end()) {
            cout << -1 << '\n';
            return 0;
        } else {
            result.push_back(*it);
            yeongjae.erase(it); // 해당 봉투 사용됨
        }
    }

    for (int r : result) {
        cout << r << ' ';
    }
    cout << '\n';

    return 0;
}

// 세종이는 i일째 되는 날에 A만큼 분노
// i일에 A원 이상 돈을 못 받으면 화 냄
// 영재는 N개의 자루에 나누어서 하루에 한 자루씩 > 그리디?
// 영재가 세종이의 분노를 피해 빚을 갚는 방법은?

// 유예 기간의 날짜 수 N
// N개의 양의 정수
// A는 i번째 날에 세종이가 받아야 하는 최소 금액
