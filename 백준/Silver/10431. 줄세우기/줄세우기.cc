#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p;
    cin >> p;

    vector<int> v(21, 0);

    for (int i = 0; i < p; i++) {
        int num, cnt = 0;
        cin >> num;

        for (int j = 0; j < 20; j++) {
            cin >> v[j];
        }

        for (int a = 0; a < 20; a++) {
            for (int b = 0; b < a; b++) {
                if (v[b] > v[a]) cnt++;
            }
        }

        cout << num << " " << cnt << '\n';
    }

    return 0;
}