#include <iostream>
#include <vector>

using namespace std;

int calculate_y(int time) {
    return (time / 30 + 1) * 10; 
}

int calculate_m(int time) {
    return (time / 60 + 1) * 15;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> times(N);
    int money_y = 0, money_m = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> times[i];
        money_y += calculate_y(times[i]);
        money_m += calculate_m(times[i]);
    }
    
    if (money_y < money_m) {
        cout << "Y " << money_y << endl;
    } else if (money_y > money_m) {
        cout << "M " << money_m << endl;
    } else {
        cout << "Y M " << money_y << endl;
    }
    
    return 0;
}