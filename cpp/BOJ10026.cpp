#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> get_start_pos(const vector<vector<bool>>& visited, const int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

int get_num_graphs_normal(const vector<vector<char>>& map, const int n) {
    int num_graphs = 0;

    queue<pair<int, int>> candidates;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    while(true) {
        candidates.emplace(get_start_pos(visited, n));
        if(candidates.front() == make_pair(-1, -1)) {
            break;
        }
        const char color = map[candidates.front().first][candidates.front().second];
        while(!candidates.empty()) {
            int row_pos = candidates.front().first;
            int col_pos = candidates.front().second;
            candidates.pop();
            if(!visited[row_pos][col_pos]) {
                visited[row_pos][col_pos] = true;

                if(row_pos - 1 >= 0 && !visited[row_pos - 1][col_pos] && map[row_pos - 1][col_pos] == color) {
                    candidates.emplace(row_pos - 1, col_pos);
                }
                if(row_pos + 1 < n && !visited[row_pos + 1][col_pos] && map[row_pos + 1][col_pos] == color) {
                    candidates.emplace(row_pos + 1, col_pos);
                }
                if(col_pos - 1 >= 0 && !visited[row_pos][col_pos - 1] && map[row_pos][col_pos - 1] == color) {
                    candidates.emplace(row_pos, col_pos - 1);
                }
                if(col_pos + 1 < n && !visited[row_pos][col_pos + 1] && map[row_pos][col_pos + 1] == color) {
                    candidates.emplace(row_pos, col_pos + 1);
                }
            }
        }
        num_graphs++;
    }

    return num_graphs;
}

int get_num_graphs_blindness(const vector<vector<char>>& map, const int n) {
    int num_graphs = 0;

    queue<pair<int, int>> candidates;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    while(true) {
        candidates.emplace(get_start_pos(visited, n));
        if(candidates.front() == make_pair(-1, -1)) {
            break;
        }
        const char color = map[candidates.front().first][candidates.front().second];
        while(!candidates.empty()) {
            int row_pos = candidates.front().first;
            int col_pos = candidates.front().second;
            candidates.pop();
            if(!visited[row_pos][col_pos]) {
                visited[row_pos][col_pos] = true;

                if(color == 'R' || color == 'G') {
                    if(row_pos - 1 >= 0 && !visited[row_pos - 1][col_pos] && (map[row_pos - 1][col_pos] == 'R' || map[row_pos - 1][col_pos] == 'G')) {
                        candidates.emplace(row_pos - 1, col_pos);
                    }
                    if(row_pos + 1 < n && !visited[row_pos + 1][col_pos] && (map[row_pos + 1][col_pos] == 'R' || map[row_pos + 1][col_pos] == 'G')) {
                        candidates.emplace(row_pos + 1, col_pos);
                    }
                    if(col_pos - 1 >= 0 && !visited[row_pos][col_pos - 1] && (map[row_pos][col_pos - 1] == 'R' || map[row_pos][col_pos - 1] == 'G')) {
                        candidates.emplace(row_pos, col_pos - 1);
                    }
                    if(col_pos + 1 < n && !visited[row_pos][col_pos + 1] && (map[row_pos][col_pos + 1] == 'R' || map[row_pos][col_pos + 1] == 'G')) {
                        candidates.emplace(row_pos, col_pos + 1);
                    }
                }
                else if(color == 'B') {
                    if(row_pos - 1 >= 0 && !visited[row_pos - 1][col_pos] && map[row_pos - 1][col_pos] == 'B') {
                        candidates.emplace(row_pos - 1, col_pos);
                    }
                    if(row_pos + 1 < n && !visited[row_pos + 1][col_pos] && map[row_pos + 1][col_pos] == 'B') {
                        candidates.emplace(row_pos + 1, col_pos);
                    }
                    if(col_pos - 1 >= 0 && !visited[row_pos][col_pos - 1] && map[row_pos][col_pos - 1] == 'B') {
                        candidates.emplace(row_pos, col_pos - 1);
                    }
                    if(col_pos + 1 < n && !visited[row_pos][col_pos + 1] && map[row_pos][col_pos + 1] == 'B') {
                        candidates.emplace(row_pos, col_pos + 1);
                    }
                }
            }
        }
        num_graphs++;
    }

    return num_graphs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<char>> map(n, vector<char>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    cout << get_num_graphs_normal(map, n) << " " << get_num_graphs_blindness(map, n);

    return 0;
}