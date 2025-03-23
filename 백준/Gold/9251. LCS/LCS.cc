#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int lcs[1001][1001];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string text1, text2;
    cin >> text1 >> text2;

    lcs[0][0] = 0;

    for (int i = 1; i <= text1.length(); i++) {
        for (int j = 1; j <= text2.length(); j++) {
            if (text1[i-1] == text2[j-1]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            } else {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }

    cout << lcs[text1.length()][text2.length()] << '\n';
   
    return 0;
}