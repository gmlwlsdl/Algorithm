// 각자 문제에 대한 난이도를 측정하고
// 최종적으로 서로가 푼 문제에 대한 난이도의 합이 최소화 되는 합을 구해야 함!

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 150000 + 1;
const int INF = 987654321;

int N;
int arr[3][MAX];       // 각 사람이 문제마다 매긴 난이도
int pSum[3][MAX];      // 누적합 (prefix sum)
int cache[3][3][MAX];  // DP 메모이제이션 (현재 담당자, 이전 담당자, 문제 번호)

// idx 번째 문제를 cur 사람이 맡고, 이전 문제를 prev 사람이 맡았을 때, 남은 최소합
int minSum(int cur, int prev, int idx) {
    int &result = cache[cur][prev][idx];
    if (result != -1) return result;

    result = INF;

    // 현재 사람과 이전 사람이 같은 경우
    if (cur == prev) {
        // 남은 사람 2명이 문제를 최소 1개씩 맡아야 하므로 idx는 N - 3 미만이어야 함
        if (idx < N - 3)
            result = min(result, minSum(cur, prev, idx + 1));

        // 다른 사람에게 넘기기
        for (int i = 0; i < 3; i++) {
            if (i != cur) {
                result = min(result, minSum(i, cur, idx + 1));
            }
        }
    } 
    // 현재 사람과 이전 사람이 다른 경우
    else {
        // 아직 마지막 사람을 쓰기 전
        if (idx < N - 2)
            result = min(result, minSum(cur, prev, idx + 1));

        // 마지막 사람에게 남은 구간 전부 넘기기 (누적합 사용)
        for (int i = 0; i < 3; i++) {
            if (i != cur && i != prev) {
                result = min(result, pSum[i][N] - pSum[i][idx + 1]);
            }
        }
    }

    // 자기 난이도 더하기
    result += arr[cur][idx];
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    // 입력 받으면서 prefix sum 계산
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            pSum[i][j + 1] = pSum[i][j] + arr[i][j];
        }
    }

    memset(cache, -1, sizeof(cache));

    int answer = INF;

    // 0, 1, 2번 사람을 각각 처음 담당자로 시작해서 최솟값 계산
    for (int i = 0; i < 3; i++) {
        answer = min(answer, minSum(i, i, 0));
    }

    cout << answer << '\n';
    return 0;
}