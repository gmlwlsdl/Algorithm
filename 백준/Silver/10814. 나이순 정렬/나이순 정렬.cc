#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<pair<int, int>, string>> list;

    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;

        list.push_back({{age, i}, name});
    }

    // 입력 받은 순서는 유지하되, 새로운 조건을 추가로 걸음
    stable_sort(list.begin(), list.end(), [](auto &a, auto &b) {

        // a의 age가 b의 age보다 작으면 a를 앞에 위치시킴
        // 그게 아니면 b를 앞에 위치시킴
        return a.first.first < b.first.first;
    });

    for (auto l:list) {
        cout << l.first.first << " " << l.second << '\n';
    }

    return 0;
}