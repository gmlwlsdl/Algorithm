// 루트부터 아래로 내려올 때 합이 최대가 되는 경로를 구하자
// 대각선 왼/오 만 이동 가능
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector <int>> triangle(n);

    for (int i = 0; i < n; i++) {
        // i 번째 줄은 숫자가 i+1개만 있음
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    // 아래에서 두 번째 줄부터 올라오면서 비교하기 
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }

    cout << triangle[0][0] << '\n';

    return 0;
}