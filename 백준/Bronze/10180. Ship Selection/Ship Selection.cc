// v denotes top speed of ship
// f denotes fuel of ship
// c denotes fuel consumption of ship per hour
// c : v = 1 : x 

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int N, D, cnt = 0;
        cin >> N >> D;

        while(N--) {
            double v, f, c, x;
            cin >> v >> f >> c;

            x = v / c;

            if (x * f >= D) cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
    
}