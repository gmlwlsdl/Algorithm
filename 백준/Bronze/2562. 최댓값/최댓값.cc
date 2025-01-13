#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> list(9);
    
    for (int i = 0; i < 9; i++) {
        cin >> list[i];
    }
    
    auto max_it = max_element(list.begin(), list.end());
    int max_value = *max_it;       
    int max_index = max_it - list.begin(); 
    
    cout << max_value << endl;
    cout << max_index+1 << endl;
    
    return 0;
}