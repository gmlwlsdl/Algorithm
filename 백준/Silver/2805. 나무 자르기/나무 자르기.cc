#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, goal, max = 0;

    cin >> n >> goal;

    vector<long long> trees(n);

    for (long long i = 0; i < n; i++) {
        cin >> trees[i];
    }

    sort(trees.begin(), trees.end());

    long long start = 0;
    long long end = trees[n-1];

    while (start <= end) {
        long long total = 0;
        long long mid = (start + end) / 2;

        for (int i = 0; i < n; i++) {
            if (trees[i] - mid > 0) total += trees[i] - mid;
        }

        if (total >= goal) {
            max = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << max << '\n';
    
    return 0;
}

// 목제 절단기는
// 높이 h를 지정
// 톱날이 땅으로부터 h미터 위로 올라감
// 한 줄에 연속해있는 나무를 모두 절단
// 높이가 H보다 큰 나무는 h 위의 부분이 잘림
// 낮은 나무는 안 잘림
// 20 15 10 17
// 절단기는 양의 정수 or 0으로 지정
// 적어도 m미터의 나무를 가져가기 위해 설정할 수 있는 높이의 최댓값

// max 나무 길이
// min 나무 길이
