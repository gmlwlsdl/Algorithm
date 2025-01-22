#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string parentheses;
    stack<int> st;
    int count = 0;

    cin >> parentheses;

    for (size_t i = 0; i < parentheses.length(); i++) {
        if (parentheses[i] == '(') {
            st.push('(');
        } else {
            st.pop();

            if (i > 0 && parentheses[i - 1] == '(') {
                count += st.size(); 
            } else {
                count++; 
            }
        }
    }

    cout << count << '\n';

    return 0;
}