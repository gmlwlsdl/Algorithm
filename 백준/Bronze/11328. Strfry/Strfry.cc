#include <iostream>

using namespace std;

int main() {
    int N;
    string a, b;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int arr_a[26] = {}, arr_b[26] = {};
        cin >> a >> b;
        
        for (auto idx:a) {
            arr_a[idx - 'a']++;
        }
        for (auto idx:b) {
            arr_b[idx - 'a']++;
        }
        
        for (int j = 0; j <= 26; j++) {
            if (j == 26) {
                cout << "Possible" << '\n';
                break;
            } else if (arr_a[j] != arr_b[j]) {
                cout << "Impossible" << '\n';
                break;
            }
        }

    }
}

// strfry 재배열