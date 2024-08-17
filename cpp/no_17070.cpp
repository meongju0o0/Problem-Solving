#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

#define HORIZON (-100)
#define VERTICAL (-200)
#define DIAGONAL (-300)

using namespace std;

int get_path_cnt(const vector<vector<int>>& map, const int n) {
    queue<tuple<int, int, int>> candidates;
    int path_cnt = 0;

    candidates.emplace(1, 2, HORIZON);

    while(!candidates.empty()) {
        tuple<int, int, int> cur_pos = candidates.front();
        candidates.pop();
        const int y_pos = get<0>(cur_pos);
        const int x_pos = get<1>(cur_pos);
        const int cur_state = get<2>(cur_pos);

        if(y_pos == n && x_pos == n) {
            path_cnt++;
        }

        if(!map[y_pos][x_pos]) {
            if(cur_state == HORIZON) {
                if(!map[y_pos][x_pos + 1]) {
                    candidates.emplace(y_pos, x_pos + 1, HORIZON);
                }
                if(!map[y_pos + 1][x_pos] && !map[y_pos][x_pos + 1] && !map[y_pos + 1][x_pos + 1]) {
                    candidates.emplace(y_pos + 1, x_pos + 1, DIAGONAL);
                }
            }
            else if(cur_state == VERTICAL) {
                if(!map[y_pos + 1][x_pos]) {
                    candidates.emplace(y_pos + 1, x_pos, VERTICAL);
                }
                if(!map[y_pos + 1][x_pos] && !map[y_pos][x_pos + 1] && !map[y_pos + 1][x_pos + 1]) {
                    candidates.emplace(y_pos + 1, x_pos + 1, DIAGONAL);
                }
            }
            else if(cur_state == DIAGONAL) {
                if(!map[y_pos][x_pos + 1]) {
                    candidates.emplace(y_pos, x_pos + 1, HORIZON);
                }
                if(!map[y_pos + 1][x_pos]) {
                    candidates.emplace(y_pos + 1, x_pos, VERTICAL);
                }
                if(!map[y_pos + 1][x_pos] && !map[y_pos][x_pos + 1] && !map[y_pos + 1][x_pos + 1]) {
                    candidates.emplace(y_pos + 1, x_pos + 1, DIAGONAL);
                }
            }
        }
    }

    return path_cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> map(n + 2, vector<int>(n + 2, 1));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    printf("%d", get_path_cnt(map, n));

    return 0;
}