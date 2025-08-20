#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> vec;
    
    for (auto n: numbers) {
        vec.push_back(to_string(n));
    }
    
    // 앞, 뒤 숫자를 더했을 때 더 큰 값이 되는 순서로 정렬
    sort(vec.begin(), vec.end(), [](string& vec1, string& vec2) {
        return vec1 + vec2 > vec2 + vec1;
    });
    
    for (auto v: vec) {
        answer += v;
    }
    
    if (answer == string(answer.length(), '0')) {
        answer = '0';
    }
    
    return answer;
}