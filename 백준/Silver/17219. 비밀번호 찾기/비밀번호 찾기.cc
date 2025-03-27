#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    map<string, string> list;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string site, pw;
        cin >> site >> pw;
        list.insert({site, pw});
    }

    for (int i = 0; i < m; i++) {
        string where;
        cin >> where;

        if (list.find(where) != list.end()) {
            cout << list.at(where) << '\n';
        }
    }

    return 0;
}