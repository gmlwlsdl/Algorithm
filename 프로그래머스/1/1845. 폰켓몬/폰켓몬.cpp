// 최대한 다양한 종류의 포켓몬 갖기
// n/2마리의 포켓몬을 선택하는 방법 중, 가장 많은 종류의 포켓몬을 선택하는 방법

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int maxValue = nums.size() / 2;
    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    if (maxValue > nums.size()) {
        return nums.size();
    } else {
        return maxValue;
    }
}