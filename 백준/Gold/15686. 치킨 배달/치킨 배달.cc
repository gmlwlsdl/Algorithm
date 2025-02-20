// N * N칸인 도시
// 각 칸은 빈 칸, 치킨집
// (r, c) 행 열 1부터 시작
// 치킨 거리 == 집과 가장 가까운 치킨집 사이의 거리
// 도시의 치킨 거리 == 모든 집의 치킨 거리의 합
// 도시의 치킨 거리가 최소가 되도록 치킨집을 살려두자
// 0 빈 칸, 1 집, 2 치킨 집

// M개는 폐업시키지 않는다 == M개를 살린다 == 치킨 거리가 짧은 치킨집 N개만 남긴다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> houses, chickens;
vector<vector<int>> city;
int minChickenDist = 9999;

// 치킨 거리 계산 함수
int getChickenDist(vector<pair<int, int>>& selectedChickens) {
    int totalDist = 0;

    // 모든 집에 대해 가장 가까운 치킨집과의 거리 찾기
    for (auto house : houses) {
        int hx = house.first;
        int hy = house.second;
        int minDist = 9999; 

        // 하나씩 위치 계산
        for (auto chicken : selectedChickens) {
            int cx = chicken.first;
            int cy = chicken.second;
            int dist = abs(hx - cx) + abs(hy - cy); // 거리 계산
            minDist = min(minDist, dist);
        }

        totalDist += minDist;
    }

    return totalDist;
}

// 치킨집 M개 선택하는 조합 생성
void selectChickens(int idx, vector<pair<int, int>> selected) {
    if (selected.size() == M) {
        minChickenDist = min(minChickenDist, getChickenDist(selected));
        return;
    }

    // 존재하는 치킨집은 모두 selected에 추가
    for (int i = idx; i < chickens.size(); i++) {
        selected.push_back(chickens[i]);
        selectChickens(i + 1, selected);
        selected.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    city.assign(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> city[i][j];

            if (city[i][j] == 1) {
                houses.push_back({i, j});
            }

            if (city[i][j] == 2) {
                chickens.push_back({i, j});
            }
        }
    }

    selectChickens(0, {});

    cout << minChickenDist << '\n';
    return 0;
}