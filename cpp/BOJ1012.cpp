#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

tuple<int, int> get_start_pos(const vector<vector<int>>& map, const int n, const int m) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(map[i][j]) {
                return make_tuple(i, j);
            }
        }
    }
    return make_tuple(-1, -1);
}

int num_graphs(vector<vector<int>>& map, const int n, const int m) {
    int num_graphs = 0;
    queue<tuple<int, int>> candidates;

    while(true) {
        tuple<int, int> start_pos = get_start_pos(map, n, m);
        if(start_pos == make_tuple(-1, -1)) {
            break;
        }
        else {
            num_graphs++;
            candidates.push(start_pos);
            while(!candidates.empty()) {
                tuple<int, int> cur_pos = candidates.front();
                candidates.pop();
                const int y_pos = get<0>(cur_pos);
                const int x_pos = get<1>(cur_pos);
                if(map[y_pos][x_pos]) {
                    map[y_pos][x_pos] = 0;
                    if(map[y_pos - 1][x_pos]) {
                        candidates.emplace(y_pos - 1, x_pos);
                    }
                    if(map[y_pos + 1][x_pos]) {
                        candidates.emplace(y_pos + 1, x_pos);
                    }
                    if(map[y_pos][x_pos - 1]) {
                        candidates.emplace(y_pos, x_pos - 1);
                    }
                    if(map[y_pos][x_pos + 1]) {
                        candidates.emplace(y_pos, x_pos + 1);
                    }
                }
            }
        }
    }

    return num_graphs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<int>> map(n + 2, vector<int>(m + 2, 0));

        while(k--) {
            int x, y;
            cin >> x >> y;
            map[y+1][x+1] = 1;
        }

        printf("%d\n", num_graphs(map, n, m));
    }

    return 0;
}