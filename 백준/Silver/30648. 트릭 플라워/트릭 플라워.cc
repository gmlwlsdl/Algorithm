#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, r, cnt = 0;
    cin >> a >> b >> r;

    vector<vector<bool>> visited;
    visited.resize(10001, vector<bool>(10001, false));

    visited[a][b] = true;

    while(1) {
        if ((a+1) + (b+1) < r) {
            a++;
            b++;
        } else {
            a /= 2;
            b /= 2;
        }
        
        cnt++;

        if (visited[a][b]) {
            break;
        }

        visited[a][b] = true;
    }

    cout << cnt << '\n';
   
    return 0;
}