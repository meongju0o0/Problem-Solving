#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

void get_path_cnt(vector<vector<int>>& map, const int n, const int y1, const int x1) {
    queue<tuple<int, int>> candidates;

    candidates.emplace(y1, x1);
    map[y1][x1] = 0;

    while(!candidates.empty()) {
        tuple<int, int> cur_pos = candidates.front();
        candidates.pop();
        const int y_pos = get<0>(cur_pos);
        const int x_pos = get<1>(cur_pos);
        const int cur_path_cnt = map[y_pos][x_pos];

        if((y_pos - 1 >= 0 && x_pos - 2 >= 0) && cur_path_cnt + 1 < map[y_pos - 1][x_pos - 2]) {
            candidates.emplace(y_pos - 1, x_pos - 2);
            map[y_pos - 1][x_pos - 2] = cur_path_cnt + 1;
        }
        if((y_pos - 2 >= 0 && x_pos - 1 >= 0) && cur_path_cnt + 1 < map[y_pos - 2][x_pos - 1]) {
            candidates.emplace(y_pos - 2, x_pos - 1);
            map[y_pos - 2][x_pos - 1] = cur_path_cnt + 1;
        }
        if((y_pos - 1 >= 0 && x_pos + 2 < n) && cur_path_cnt + 1 < map[y_pos - 1][x_pos + 2]) {
            candidates.emplace(y_pos - 1, x_pos + 2);
            map[y_pos - 1][x_pos + 2] = cur_path_cnt + 1;
        }
        if((y_pos - 2 >= 0 && x_pos + 1 < n) && cur_path_cnt + 1 < map[y_pos - 2][x_pos + 1]) {
            candidates.emplace(y_pos - 2, x_pos + 1);
            map[y_pos - 2][x_pos + 1] = cur_path_cnt + 1;
        }
        if((y_pos + 1 < n && x_pos - 2 >= 0) && cur_path_cnt + 1 < map[y_pos + 1][x_pos - 2]) {
            candidates.emplace(y_pos + 1, x_pos - 2);
            map[y_pos + 1][x_pos - 2] = cur_path_cnt + 1;
        }
        if((y_pos + 2 < n && x_pos - 1 >= 0) && cur_path_cnt + 1 < map[y_pos + 2][x_pos - 1]) {
            candidates.emplace(y_pos + 2, x_pos - 1);
            map[y_pos + 2][x_pos - 1] = cur_path_cnt + 1;
        }
        if((y_pos + 1 < n && x_pos + 2 < n) && cur_path_cnt + 1 < map[y_pos + 1][x_pos + 2]) {
            candidates.emplace(y_pos + 1, x_pos + 2);
            map[y_pos + 1][x_pos + 2] = cur_path_cnt + 1;
        }
        if((y_pos + 2 < n && x_pos + 1 < n) && cur_path_cnt + 1 < map[y_pos + 2][x_pos + 1]) {
            candidates.emplace(y_pos + 2, x_pos + 1);
            map[y_pos + 2][x_pos + 1] = cur_path_cnt + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> map(n, vector<int>(n, INT_MAX));

        int x1, y1, x2, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        get_path_cnt(map, n, y1, x1);

        printf("%d\n", map[y2][x2]);
    }

    return 0;
}