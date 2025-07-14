// courtyard의 면적 받으면
// sqrt로 한 변의 길이 구하고
// 총 필요한 조명의 길이 출력

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double area;
    cin >> area;

    double edge;
    edge = sqrt(area);

    cout << setprecision(8) << edge * 4 << '\n';

    return 0;
}