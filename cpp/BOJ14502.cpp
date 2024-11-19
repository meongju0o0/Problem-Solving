#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

#define KEY_MUL 10

using namespace std;

inline int gen_key(const int y_pos, const int x_pos) {
    return y_pos * KEY_MUL + x_pos;
}

int spread_virus(vector<vector<int>>& map, const unordered_set<int>& virus_pos_set) {
    int infected_cnt = 0;
    queue<int> cands;

    for(const int& virus_pos : virus_pos_set) {
        cands.push(virus_pos);
    }

    while(!cands.empty()) {
        const int cur_pos = cands.front();
        const int cur_y = cur_pos / KEY_MUL;
        const int cur_x = cur_pos % KEY_MUL;
        cands.pop();

        for (const auto& [dy, dx] : vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            const int next_y = cur_y + dy, next_x = cur_x + dx;
            const int next_pos = gen_key(next_y, next_x);

            if (map[next_y][next_x] == 0) {
                map[next_y][next_x] = 2;
                infected_cnt++;
                cands.push(next_pos);
            }
        }
    }

    return infected_cnt;
}

int max_safe_area(const vector<vector<int>>& map, const vector<pair<int, int>>& safe_areas, const unordered_set<int>& virus_pos_set, const int total_safe) {
    int max_area = 0;
    const size_t size = safe_areas.size();

    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            for(int k = j + 1; k < size; k++) {
                vector<vector<int>> temp_map = map;

                temp_map[safe_areas[i].first][safe_areas[i].second] = 1;
                temp_map[safe_areas[j].first][safe_areas[j].second] = 1;
                temp_map[safe_areas[k].first][safe_areas[k].second] = 1;

                const int infected = spread_virus(temp_map, virus_pos_set);
                max_area = max(max_area, total_safe - infected - 3);
            }
        }
    }

    return max_area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n + 2, vector<int>(m + 2, 1));
    vector<pair<int, int>> safe_areas;
    unordered_set<int> virus_pos_set;
    int safe_count = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                virus_pos_set.insert(gen_key(i, j));
            }
            else if(map[i][j] == 0) {
                safe_areas.emplace_back(i, j);
                safe_count++;
            }
        }
    }

    printf("%d", max_safe_area(map, safe_areas, virus_pos_set, safe_count));

    return 0;
}