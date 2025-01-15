#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
	int K, sum = 0;
	cin >> K;

	stack<int> stack;

	for (int i = 0; i < K; i++) {
		int value;
		cin >> value;
		if (value == 0) {
			stack.pop();
		} else {
			stack.push(value);
		}
	}

	while(!stack.empty()) {
		sum += stack.top();
		stack.pop();
	}

	cout << sum << endl;
        
    return 0;
}