#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    long long total = 0;
    cin >> N;

    stack<int> building;

    for (int i = 0; i < N; i++) {
        long long height;
        cin >> height;
        
        if (i == 0) {
            building.push(height);
            continue;
        } 
        
        while (!building.empty() && building.top() <= height) {
            building.pop();
        }
        
        total += building.size();
        building.push(height);
    }

    cout << total << '\n';

    return 0;
}