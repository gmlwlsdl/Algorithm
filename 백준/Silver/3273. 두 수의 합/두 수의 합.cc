#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
 
    int n, goal, count = 0;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cin >> goal;
    
    unordered_map<int, int> frequency;
    
    for (int i = 0; i < n; i++) {
        int m = goal-arr[i];
        
        if (frequency[m] > 0) {
            count += frequency[m];
        }
        
        frequency[arr[i]]++;
    }
    
    cout << count;
    return 0;
}