#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, a, b;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << a + b << "\n";
    }
    
    return 0;
}

// 전부 입력받아서 전부 출력하지 않아도 됨
// sync_with_stdio(false) -> 원래는 c랑 c++이랑 동일한 버퍼를 공유하는데, 그래서 딜레이가 발생함
