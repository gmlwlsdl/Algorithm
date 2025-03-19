#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector<string> see;
    map<string, int> hear;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        hear.insert({name, i});
    }

    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;

        if (hear.find(name) != hear.end()) {
            see.push_back(name);
        } else {
            continue;
        }
    }

    sort(see.begin(), see.end());

    cout << see.size() << '\n';

    for (auto who : see) {
        cout << who << '\n';
    }
    
    return 0;
}