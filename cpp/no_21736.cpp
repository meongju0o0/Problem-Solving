#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> get_start_pos(const vector<vector<char>>& map, const int n, const int m) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(map[i][j] == 'I') {
                return make_pair(i, j);
            }
        }
    }
}

int num_vistable_people(const vector<vector<char>>& map, const int n, const int m) {
    int num_visitable_people = 0;
    queue<pair<int, int>> candidates;
    vector<vector<bool>> visited(n + 2, vector<bool>(m + 2, false));

    candidates.emplace(get_start_pos(map, n, m));
    while(!candidates.empty()) {
        int row_pos = candidates.front().first;
        int col_pos = candidates.front().second;
        candidates.pop();

        if(!visited[row_pos][col_pos]) {
            visited[row_pos][col_pos] = true;

            if(map[row_pos][col_pos] == 'P') {
                num_visitable_people++;
            }

            if(!visited[row_pos - 1][col_pos] && (map[row_pos - 1][col_pos] == 'O' || map[row_pos - 1][col_pos] == 'P')) {
                candidates.emplace(row_pos - 1, col_pos);
            }
            if(!visited[row_pos + 1][col_pos] && (map[row_pos + 1][col_pos] == 'O' || map[row_pos + 1][col_pos] == 'P')) {
                candidates.emplace(row_pos + 1, col_pos);
            }
            if(!visited[row_pos][col_pos - 1] && (map[row_pos][col_pos - 1] == 'O' || map[row_pos][col_pos - 1] == 'P')) {
                candidates.emplace(row_pos, col_pos - 1);
            }
            if(!visited[row_pos][col_pos + 1] && (map[row_pos][col_pos + 1] == 'O' || map[row_pos][col_pos + 1] == 'P')) {
                candidates.emplace(row_pos, col_pos + 1);
            }
        }
    }

    return num_visitable_people;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n + 2, vector<char>(m + 2, 'X'));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }

    int result = num_vistable_people(map, n, m);
    if(result > 0) {
        cout << result;
    }
    else {
        cout << "TT";
    }

    return 0;
}