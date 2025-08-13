// 만들 수 있는 수열 중에서
// 입려된 수열 다음 수열을 구하기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool next_permutation(vector <int> &arr, int n) {
    // 어디까지 내림차순인지, 그 시작을 알아야 함
    // 변수 i를 맨 끝 인덱스로 설정하여 뒤에서부터 조회
    // 마지막으로 설정되는 i 값이 내림차순이 시작되는 인덱스
    int i = n;
    while (i > 0 && (arr[i - 1] >= arr[i])) {
        i -= 1;
    }

    // 이미 순열이 내림차순이므로 더이상 뒤에 올 순열 조합이 없음
    if (i == 1) {
        return false;
    }

    // 이제 내림차순의 앞 인덱스와 내림차순쪽 순열에서, 내림차순의 앞 수보다 큰 최초의 수를 조회
    int j = n;
    while (arr[j] <= arr[i - 1]) {
        j -= 1;
    }
    // 찾았으면 두 수를 swap
    swap(arr[i-1], arr[j]);

    // 다시 j를 순열의 맨 끝 인덱스로 조정
    j = n;

    // 이제 바꾼 수 기준 뒷 수를 내림차순으로 다시 정렬
    while (i < j) {
        swap(arr[i], arr[j]);
        i += 1; // i는 올라와야 함
        j -= 1; // j는 맨 뒤에서 내려와야 함
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    if (next_permutation(arr, n)) {
        for (int i = 1; i <= n; i++) {
            cout << arr[i];
            i < n ? cout << ' ' : cout << '\n';
        }
    } else {
        cout << "-1" << '\n';
    }

    return 0;
}