#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string sentence;
    
    int count = 0;

    while(1) {
        stack<char> st;
        getline(cin, sentence);

        if (sentence[0] == '.') {
            break;
        }

        for (auto s:sentence) {
            if (s == '(' || s == ')' || s == '[' || s == ']') {
                if (!st.empty() && st.top() == '(' && s == ')') {
                    st.pop();
                } else if (!st.empty() && st.top() == '[' && s == ']') {
                    st.pop();
                } else {
                    st.push(s);
                }
            }
        }

        if (st.empty()) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
    
    return 0;
}