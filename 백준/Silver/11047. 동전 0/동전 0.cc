// 동전의 가치로 원하는 금액 만들기
// 필요한 동전 개수의 최솟값 찾기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int i, int j) {
    return j < i;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, k, cnt = 0;
    cin >> n >> k;

    vector<int> values;
    values.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    sort(values.begin(), values.end(), compare); // 내림차순 정렬

   for (int i = 0; i < n; i++) {

        while(1) {

            if (values[i] <= k && k-values[i] >= 0 && k != 0) {
                k -= values[i];
                cnt++;
            } else {
                break;
            }
        }
   }

    cout << cnt << '\n';

    return 0;
}