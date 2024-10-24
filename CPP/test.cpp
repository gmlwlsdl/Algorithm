#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};

    // []에는 캡처할 변수를 넣음
    // 캡처할 변수 != 파라미터, 해당 람다 함수의 외부에 있는 변수에 접근할 때 사용
    // [&]는 모든 변수를 참조로 캡처한다는 뜻
    auto printNumber = [](int n) {
        cout << n << " ";
    };

    cout << "Numbers: ";
    for_each(numbers.begin(), numbers.end(), printNumber);
    cout << endl;

    cout << "Doubled Numbers: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n * 2 << " ";
    });
    cout << endl;

    return 0;
}