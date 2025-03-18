#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    vector<int> v;
    vector<int> sum;
    
    cin >> n >> m;

    v.assign(n, 0);
    sum.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i == 0) {
            sum[i] = v[i];
            continue;
        }
        sum[i] = sum[i-1] + v[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b = 0;
        cin >> a >> b;
 
        cout << sum[b-1] - sum[a-1] + v[a-1] << '\n';
    }
   
    return 0;
}