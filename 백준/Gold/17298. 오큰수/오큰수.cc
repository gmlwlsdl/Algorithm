#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);      
    vector<int> result(N);  
    stack<int> st;          

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        while (!st.empty() && A[st.top()] < A[i]) {
            result[st.top()] = A[i]; 
            st.pop();               
        }
        st.push(i); 
    }

    while (!st.empty()) {
        result[st.top()] = -1;
        st.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
    cout << '\n';

    return 0;
}