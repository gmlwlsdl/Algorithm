#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        int n, distance = 0, elapsed = 0;
        cin >> n;

        if (n == -1) break;

        while(n--) {
            int s, t;
            cin >> s >> t;

            distance += s * (t-elapsed);
            
            elapsed = t;
        }

        cout << distance << " miles" << endl;

    }
    
    return 0;
    
}