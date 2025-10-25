#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    unordered_set<int> count[8]; // N을 n번 사용해서 만들 수 있는 수의 개수 카운트

    int sum = 0;
    for (int i = 0; i < 8; i++) {
        sum = 10 * sum + N; // N을 i번 사용해서 만드는 수 ex)2, 22, 222, ...
        count[i].insert(sum);
    }
    
    // N을 1번 사용해서 만드는 건(count[0]) 1번밖에 없음
    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            for (auto a: count[j]) {
                for (auto b: count[i-j-1]) {
                    count[i].insert(a + b);
                    count[i].insert(a - b);
                    count[i].insert(a * b);
                    
                    // ZeroDivisionError 고려
                    if (b != 0) {
                        count[i].insert(a / b);
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < 8; i++) {
        if (count[i].find(number) != count[i].end()) {
            // 가장 작은 경우의 수일 때 반환
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}