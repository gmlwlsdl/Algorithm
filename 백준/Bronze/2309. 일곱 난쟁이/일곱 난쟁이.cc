#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int sum = 0;
    vector<int> list(9);
    
    for (int i = 0; i < 9; i++) {
        cin >> list[i];
        sum += list[i];
    }
    
    sort(list.begin(), list.end());
    
    for (int i = 0; i < 9; i++) {
        for (int j = i+1; j < 9; j++) {
            if ( sum - (list[i]+list[j]) == 100) {
                for (int k = 0; k < 9; k++) {
                    if (i != k && j != k) {
                        cout << list[k] << endl;
                    }
                }
                return 0;
            }
        }
    }
}