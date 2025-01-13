#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> list(3);
    
    for (int i=0; i<3; i++){
        cin >> list[i];
    }
    
    if (list[0]==list[1] && list[1]==list[2]) {
        cout << 10000 + list[0]*1000 << endl;
    } else if (list[0]==list[1] || list[0]==list[2]) {
        cout << 1000 + list[0]*100 << endl;
    } else if (list[1]==list[2]) {
        cout << 1000 + list[1]*100 << endl;
    } else {
        cout << *max_element(list.begin(), list.end())*100 << endl; 
    }
    
    return 0;
}
