// M이상 N이하의 자연수 중 완전 제곱수인 것을 골라서
// 합하고
// 그 중 최솟값을 찾아라
// 완전 제곱수 없을 때는 -1 출력

#include <iostream>

using namespace std;

int main(){
    int M =0, N = 0;
    int min = 0;
    int result = 0;

    cin >> M >> N;

    for(int i = 0; i <= 100; i++) {
        if((i*i >= M) && (i*i <= N)){
            result += (i*i);
            if(min == 0){
                min = (i*i);
            } else {
                if (min > (i*i)) {
                    min=(i*i);
                } 
            }
        } 
    }
    
    if(result == 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << result << endl;
    cout << min << endl;

    return 0;
}