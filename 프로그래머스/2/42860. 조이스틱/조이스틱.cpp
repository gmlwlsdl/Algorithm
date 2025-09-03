#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name) {
    int n = (int)name.size();

    int change = 0;
    for (char c : name) {
        change += min(c - 'A', 'Z' - c + 1);
    }

    int move = n - 1; // 일단 끝까지 쭉 오른쪽으로 가는 비용
    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        // i 다음부터 연속된 'A' 구간 찾기
        while (j < n && name[j] == 'A') ++j;

        // 전략 1) 오른쪽으로 i까지 갔다가 처음(왼쪽)으로 되돌아가서 끝으로
        move = min(move, 2 * i + (n - j));

        // 전략 2) 오른쪽 끝까지 갔다가 처음(왼쪽)으로 되돌아와 i까지
        move = min(move, 2 * (n - j) + i);
    }

    return change + move;
}