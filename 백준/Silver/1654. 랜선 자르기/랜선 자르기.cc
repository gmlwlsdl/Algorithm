#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
   long long n, k;
   unsigned int list[10000], ans = 0;
   cin >> n >> k;

   unsigned int maxi = 0;

   for (long long i = 0; i < n; i++) {
    cin >> list[i];
    maxi = max(maxi, list[i]); // 현재 입력된 값 중 최댓값 저장하고
   }

   unsigned int left = 1, right = maxi, mid;

   while (left <= right) { // 왼쪽이 오른쪽보다 작을 때
        mid = (left + right) / 2; // 중간 값 확인하고

        unsigned int now = 0; 

        for (long long i = 0; i < n; i++) {
            now += list[i] / mid; // 현재 자를 수 있는 랜선 갯수
        }

        if (now >= k) { // 너무 많이 만듬
            left = mid + 1;
            ans = max(ans, mid);
        } else { // 너무 적게 만듬
            right = mid - 1;
        }
   }

    cout << ans << '\n';

    return 0;
}
