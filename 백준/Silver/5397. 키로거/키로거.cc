#include <iostream>
#include <list>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        string password;
        cin >> password;
        
        list<char> keylogger;
        auto cursor = keylogger.begin();
        
        for (char text : password) {
            if (text == '<') {
                if (cursor != keylogger.begin()) {
                    cursor--;
                }
            } else if (text == '>') {
                if (cursor != keylogger.end()) {
                    cursor++;
                }
            } else if (text == '-') {
                if (cursor != keylogger.begin()) {
                    cursor = keylogger.erase(--cursor);
                }
            } else {
                keylogger.insert(cursor, text);
            }
        }
        
        for (char result : keylogger) {
            cout << result;
        }
        cout << '\n';
    }
    
    return 0;
}