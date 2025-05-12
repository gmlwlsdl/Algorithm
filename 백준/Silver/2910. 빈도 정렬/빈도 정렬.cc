// 빈도를 조사하는 것!
// N개로 이루어진 수열
// C보다 작거나 같음
// 숫자가 자주 등장하는 빈도대로 정렬
// 먼저 나온 것이 앞

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool compare(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
    
    // 빈도수가 같으면
    if (a.second.first == b.second.first) {

        // 등장 인덱스가 작은 애가 앞에 정렬
        return a.second.second < b.second.second;
    }

    // 빈도수가 큰 애가 앞에 정렬
    return a.second.first > b.second.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    map<int, pair<int, int>> freqMap; // 숫자, {빈도수, 첫 등장 인덱스}

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        
        // 해당 숫자가 등장한 저 없으면 숫자의 빈도수를 1로
        if (freqMap.find(value) == freqMap.end()) {
            freqMap[value] = {1, i};
        } 

        // 등장한 적 있으면 빈도수 증가
        else {
            freqMap[value].first++;
        }
    }

    // map의 pair 그대로 복사해서 벡터로 변환
    vector<pair<int, pair<int, int>>> freq(freqMap.begin(), freqMap.end());

    sort(freq.begin(), freq.end(), compare);

    for (auto f : freq) {
        for (int i = 0; i < f.second.first; i++) {
            cout << f.first << " ";
        }
    }
    cout << '\n';

    return 0;
}