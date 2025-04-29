#include <iostream>

using namespace std;

long long min(long long a, long long b) {
    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long long max(long long a, long long b) {
    return (a / min(a, b)) * b;  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long a, b;
    cin >> a >> b;

    cout << max(a, b) << endl;

    return 0;
}