#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    stack<pair<long long, int>> people;
    long long count = 0;

    for (int i = 0; i < N; i++) {
        long long height;
        cin >> height;

        while (!people.empty() && people.top().first < height) {
            count += people.top().second;
            people.pop();
        }

        if (!people.empty() && people.top().first == height) {
            int sameHeightCount = people.top().second;
            count += sameHeightCount; 
            if (people.size() > 1) { 
                count++; 
            }
            people.pop();
            people.push({height, sameHeightCount + 1});
        } else {
            if (!people.empty()) {
                count++; 
            }
            people.push({height, 1});
        }
    }

    cout << count << '\n';

    return 0;
}