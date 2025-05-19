// 슬라이딩 윈도우

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, sum = 0, count = 1;
	cin >> n >> x;

	vector<int> v;
	v.assign(n, 0);

	for (int i  = 0; i < n; i++) {
		cin >> v[i];

		if (i < x) {
			sum += v[i];
		}
	}

    int maxSum = sum;

	// x 2, i 2 3 4
    for (int i = x; i < n; i++) {
        sum = sum - v[i - x] + v[i];

        if (sum > maxSum) {
            maxSum = sum;
            count = 1;
        } else if (sum == maxSum) {
            count++;
        }
    }

    if (maxSum == 0) {
        cout << "SAD" << '\n';
    } else {
        cout << maxSum << '\n';
        cout << count << '\n';
    }

    return 0;
}