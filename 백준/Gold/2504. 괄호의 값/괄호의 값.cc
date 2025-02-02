#include <iostream>
#include <stack>
#include <string>

using namespace std;

int compare(const string &s) {
    stack<char> st;
    stack<int> values; 
    int temp = 1, result = 0;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (c == '(') {
            temp *= 2;
            st.push(c);
        } else if (c == '[') {
            temp *= 3;
            st.push(c);
        } else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                return 0;
            }

            if (s[i-1] == '(') {
                result += temp;
            }

            st.pop();
            temp /= 2;
        } else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                return 0;
            }

            if (s[i-1] == '[') {
                result += temp;
            }
            
            st.pop();
            temp /= 3;
        }
    }

    return st.empty() ? result : 0;
}

int main() {
    string s;
    cin >> s;

    cout << compare(s) << '\n';
    return 0;
}