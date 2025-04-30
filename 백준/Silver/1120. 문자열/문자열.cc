// 일단 같게 만들기
// adaabc aababbc -> 맨 앞에 a 붙이기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    int a_length = a.length(); 
    int b_length = b.length(); 
    int size = b_length - a_length + 1;

    vector<int> length(size);

    for (int i = 0; i < size; i++) {
        int dif = 0;
        int cur = i;

        for (int j = 0; j < a_length; j++) {
            if (a[j] != b[i]) {
                dif++;
            } 
            i++;
        }

        length[cur] = dif;
        i = cur;
    }

    int min = *min_element(length.begin(), length.end());

    cout << min << '\n';

    return 0;
}