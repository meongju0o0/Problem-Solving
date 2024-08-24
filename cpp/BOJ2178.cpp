#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int get_path_cnt(vector<vector<int>>& map, const int n, const int m) {
    queue<tuple<int, int>> candidates;
    unordered_map<string, int> path_cnts;

    candidates.emplace(1, 1);
    path_cnts["1,1"] = 1;

    while(!candidates.empty()) {
        tuple<int, int> cur_pos = candidates.front();
        candidates.pop();
        const int y_pos = get<0>(cur_pos);
        const int x_pos = get<1>(cur_pos);
        const int cur_path_cnt = path_cnts[to_string(y_pos) + "," + to_string(x_pos)];

        if(map[y_pos][x_pos]) {
            map[y_pos][x_pos] = 0;
            if(map[y_pos + 1][x_pos]) {
                candidates.emplace(y_pos + 1, x_pos);
                path_cnts[to_string(y_pos + 1) + "," + to_string(x_pos)] = cur_path_cnt + 1;
            }
            if(map[y_pos - 1][x_pos]) {
                candidates.emplace(y_pos - 1, x_pos);
                path_cnts[to_string(y_pos - 1) + "," + to_string(x_pos)] = cur_path_cnt + 1;
            }
            if(map[y_pos][x_pos - 1]) {
                candidates.emplace(y_pos, x_pos - 1);
                path_cnts[to_string(y_pos) + "," + to_string(x_pos - 1)] = cur_path_cnt + 1;
            }
            if(map[y_pos][x_pos + 1]) {
                candidates.emplace(y_pos, x_pos + 1);
                path_cnts[to_string(y_pos) + "," + to_string(x_pos + 1)] = cur_path_cnt + 1;
            }
        }
    }

    return path_cnts[to_string(n) + "," + to_string(m)];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n + 2, vector<int>(m + 2, 0));

    for(int i = 1; i <= n; i++) {
        string line;
        cin >> line;
        for(int j = 1; j <= m; j++) {
            map[i][j] = line.front() - '0';
            line.erase(line.begin());
        }
    }

    printf("%d\n", get_path_cnt(map, n, m));

    return 0;
}