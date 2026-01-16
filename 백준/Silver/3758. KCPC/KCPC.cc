#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Log {
    int max_score;
    int submit_cnt;
    int submit_time;
};

struct Report {
    int total_score;
    int total_submit;
    int last_submit_time;
};

int n, k, t, m;

void calc(int t, vector<vector<Log>> &table) {
    int cnt = 1;
    vector<Report> report(n + 1, Report{0, 0, 0});

    for (int i = 0; i < table.size(); i++) {
        for (auto a: table[i]) {
            report[i].total_score += a.max_score;
            report[i].total_submit += a.submit_cnt;
            report[i].last_submit_time = max(report[i].last_submit_time, a.submit_time);
        }
    }

    for (int i = 1; i < table.size(); i++) {
        if (i != t) {
            if (report[i].total_score > report[t].total_score) cnt++;
            else if (report[i].total_score == report[t].total_score) {
                if (report[i].total_submit < report[t].total_submit) {
                    cnt++;
                } else if (report[i].total_submit == report[t].total_submit) {
                    if (report[i].last_submit_time < report[t].last_submit_time) {
                        cnt++;
                    }
                }
            }
        }
    }
    
    cout << cnt << '\n';
    
    return;
 }

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> n >> k >> t >> m;

        vector<vector<Log>> table(n + 1, vector<Log>(k + 1, Log{0, 0, 0}));

        int time = 0;
        for (int l = 0; l < m; l++) {
            int i, j, s;
            cin >> i >> j >> s;

            if (table[i][j].submit_cnt != 0 ) {
                table[i][j].max_score = max(s, table[i][j].max_score);
            } else {
                table[i][j].max_score = s;
            }

            table[i][j].submit_cnt++;
            table[i][j].submit_time = time;
            time++;
        }

        calc(t, table);
    }

    return 0;
}

/* 1
3 4 3 5
1 1 30
2 3 30
1 2 40
1 2 20
3 1 70 */