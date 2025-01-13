#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    vector<int> list(3);
    cin >> list[0] >> list[1] >> list[2];
    
    sort(list.begin(), list.end());
    
    cout << list[0] << " " << list[1] << " " << list[2];
    
    return 0;
}