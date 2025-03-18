#include <iostream>

using namespace std;

void calc(int a, int b, int c) {
    if ( a*a == b*b + c*c) {
        cout << "right" << '\n';
    } else {
        cout << "wrong" << '\n';
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int a, b, c;

    
    
    while(1) {
        cin >> a >> b >> c;

        if ( a == 0 && b == 0 && c == 0 ) {
            break;
        }
    
        if ( a > b && a > c) {
            calc(a, b, c);
        }
    
        if ( b > a && b > c) {
            calc(b, a, c);
        }
    
        if ( c > a && c > b) {
            calc(c, a, b);
        }
    }
    return 0;
}