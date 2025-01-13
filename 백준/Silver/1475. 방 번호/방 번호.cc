#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string N;
    cin >> N;
    
    vector<int> count(10, 0);
    
    for (char c : N) {
        count[c - '0']++; 
    }
    
    count[6] = (count[6] + count[9] + 1) / 2;
    count[9] = count[6]; 
    
    int min_sets = *max_element(count.begin(), count.end());
    
    cout << min_sets << endl;

    return 0;
}