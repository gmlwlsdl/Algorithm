#include <iostream>
#include <string.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string text;
    int cnt = 0;

    cin >> text;

    for (auto a:text) {
        cnt++;
    }

    cout << cnt << '\n';
    
    return 0;
}