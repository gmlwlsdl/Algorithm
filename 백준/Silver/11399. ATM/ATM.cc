// ATM이 1대
// N명이 줄을 서있음
// i번째 사람이 돈 인출 > P(i)
// 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값
// 시간이 작은 사람부터 순서대로
// 1 3 6 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, sum = 0;
    cin >> n;

    vector<int> people;
    vector<int> time;

    people.assign(n, 0);
    time.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> people[i];
    }

    sort(people.begin(), people.end()); // 오름차순

    time[0] = people[0];
    sum += time[0];

    for (int i = 1; i < n; i++) {
        time[i] = time[i-1] + people[i];
        sum += time[i];
    }

    cout << sum << '\n';

    return 0;
}