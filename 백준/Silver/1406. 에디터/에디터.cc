#include <iostream>
#include <list>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    string text;
    int count;
    cin >> text;
    cin >> count;
    
    list<char> li(text.begin(), text.end());
    auto cursor = li.end();
    
    for (int i = 0; i < count; i++) {
        char move, ch;
        cin >> move;
        
        if (move == 'L') {
            if (cursor != li.begin()) {
                cursor--;
            }
        } else if (move == 'D') {
            if (cursor != li.end()) {
                cursor++;
            }
        } else if (move == 'B') {
            if (cursor != li.begin()) {
                cursor--;
                cursor = li.erase(cursor);
            }
        } else if (move == 'P') {
            cin >> ch;
            li.insert(cursor, ch);
        }
    }
    
    for (auto result:li) {
        cout << result;
    }
}