#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, result = 0;
    cin >> n;

    for (int i = 1; i <= n; i *= 10)
    {
        result += (n - i) + 1;
    }   

    cout << result << '\n';
    
    return 0;
}