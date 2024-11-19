#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define POS_MUL 1000

using namespace std;

inline int gen_pos(const int x, const int y) {
    return POS_MUL * x + y;
}

int get_start_pos(const vector<vector<int>>& map, const vector<vector<bool>>& visited, const int n, const int height) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(map[i][j] > height && !visited[i][j]) {
                return gen_pos(i, j);
            }
        }
    }

    return -1;
}

int cnt_safe_area(const vector<vector<int>>& map, const int n, const int height) {
    int cnt_area = 0;
    vector<vector<bool>> visited(n + 2, vector<bool>(n + 2, false));
    queue<int> cands;

    int start_pos = get_start_pos(map, visited, n, height);
    while(start_pos != -1) {
        cands.push(start_pos);
        cnt_area++;

        while(!cands.empty()) {
            const int cur_pos = cands.front();
            const int cur_y = cur_pos / POS_MUL;
            const int cur_x = cur_pos % POS_MUL;
            cands.pop();
            if(!visited[cur_y][cur_x]) {
                visited[cur_y][cur_x] = true;
                for(const auto& [dy, dx]: vector<pair<int, int>> {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}}) {
                    const int next_y = cur_y + dy;
                    const int next_x = cur_x + dx;
                    const int next_pos = gen_pos(next_y, next_x);
                    if(!visited[next_y][next_x] && map[next_y][next_x] > height) {
                        cands.push(next_pos);
                    }
                }
            }
        }

        start_pos = get_start_pos(map, visited, n, height);
    }

    return cnt_area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int max_height = 0;
    vector<vector<int>> map(n+2, vector<int>(n+2, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j<= n; j++) {
            cin >> map[i][j];
            max_height = max(max_height, map[i][j]);
        }
    }

    int max_safe_area = 0;
    for(int height = 0; height < max_height; height++) {
        max_safe_area = max(max_safe_area, cnt_safe_area(map, n, height));
    }

    printf("%d", max_safe_area);

    return 0;
}