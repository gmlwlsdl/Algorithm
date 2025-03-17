#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int r;
        string word;
        cin >> r >> word;

        for (int j = 0; j < word.length(); j++) {
            for (int k = 0; k < r; k++) {
                cout << word[j];
            }
        }
        cout << '\n';
    }

    return 0;
}
