#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> arr(41);

void fibonacci(int num) {
    if (num > 1) {
        int one_cnt = 0, zero_cnt = 0;

        for (int i = 2; i <= num; i++) {
            if (arr[i].first == 0 && arr[i].second == 0) {
                arr[i].first = arr[i-1].first + arr[i-2].first;
                arr[i].second = arr[i-1].second + arr[i-2].second;
            }
        }
    }
    cout << arr[num].first << " " << arr[num].second << '\n';
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    arr[0] = {1, 0}; // 0 횟수, 1 횟수
    arr[1] = {0, 1};
    
    for (int i = 0; i < t; i++) {
        int c;
        cin >> c;
        fibonacci(c);
    }

    return 0;
}
