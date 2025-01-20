#include <iostream>
#include <stack>
using namespace std;

int main()
{
    while(true)
    {
        int n;
        int arr[100001];
        stack<int> st;

        long long result = 0;
        cin >> n;

        if (n == 0) {
            return 0;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            while (!st.empty())
            {
                if (arr[i] < arr[st.top()])
                {
                    long long height = arr[st.top()];
                    st.pop();

                    long long cnt = i;

                    if (!st.empty()) {
                        cnt = i - st.top() - 1;
                    }
                    result = max(result, height * cnt);
                }
                else { 
                    break;
                }
            }
            st.push(i);
        }

        while (!st.empty())
        {
            long long height = arr[st.top()];
            st.pop();

            long long cnt = n;

            if (!st.empty()) {
                cnt = n - st.top() - 1;
            }
            result = max(result, height * cnt);
        }

        cout << result << '\n';
    }
}