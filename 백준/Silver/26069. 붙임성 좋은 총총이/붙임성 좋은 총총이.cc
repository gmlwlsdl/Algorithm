#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, cnt = 0;
    cin >> n;
    string name1, name2;
    map<string, bool> list;

    for (int i = 0; i < n; i++) {
        cin >> name1 >> name2;

        if (name1 == "ChongChong") list.insert({name1, true});

        if (name2 == "ChongChong") list.insert({name2, true});

        if (list[name1]) list[name2] = true;
        if (list[name2]) list[name1] = true;
    }

    for (auto l:list) {
        if (l.second) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}
