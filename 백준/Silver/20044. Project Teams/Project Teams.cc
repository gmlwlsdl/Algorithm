// 프로젝트 팀 하나는 두 명의 학생
// 조합의 수가 가장 고르게 분포되려면
// 오름차순으로 정렬하고
// 맨 뒤와 맨 앞을 팀으로 하는 식으로 맞춰나가야 함

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> v(2 * n);
    vector<int> result(n);

    for (int i = 0; i < (2 * n); i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int j = 2 * n - 1;

    for (int i = 0; i < n; i++) {
        result[i] = v[i] + v[j];
        j--;
    }

    cout << *min_element(result.begin(), result.end()) << '\n';

    return 0;
}