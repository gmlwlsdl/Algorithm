#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};

    auto printNumber = [](int n) {
        cout << n << " ";
    };

    cout << "Numbers: ";
    for_each(numbers.begin(), numbers.end(), printNumber);
    cout << endl;

    cout << "Doubled Numbers: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n *2 << " ";
    });
    cout << endl;

    return 0;
}