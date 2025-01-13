#include <iostream>
#include <list>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    
    list<int> li;
    for (int i = 1; i <= n; i++) {
        li.push_back(i);
    }
    
    auto it = li.begin();
    
    cout << "<";
    while(li.size() > 1) {
        for (int i = 0; i < k-1; i++) {
            it++;
            if (it == li.end()) {
                it = li.begin();
            }
        }
        
        cout << *it << ", ";
        it = li.erase(it);
        
        if (it == li.end()) {
            it = li.begin();
        }
    }
    
    cout << *it << ">";
    
    return 0;
}