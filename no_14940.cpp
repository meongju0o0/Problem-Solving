#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

vector<pair<int, int>> get_neighbors(vector<vector<int>>& map, pair<int, int>& cur_pos) {
    vector<pair<int, int>> neighbors(0);
    if(map[cur_pos.first-1][cur_pos.second] != 0) {
        neighbors.emplace_back(cur_pos.first-1, cur_pos.second);
    }
    if(map[cur_pos.first+1][cur_pos.second] != 0) {
        neighbors.emplace_back(cur_pos.first+1, cur_pos.second);
    }
    if(map[cur_pos.first][cur_pos.second-1] != 0) {
        neighbors.emplace_back(cur_pos.first, cur_pos.second-1);
    }
    if(map[cur_pos.first][cur_pos.second+1] != 0) {
        neighbors.emplace_back(cur_pos.first, cur_pos.second+1);
    }

    return neighbors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n+2, vector<int>(m+2, 0));
    pair<int, int> start_point;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                start_point = make_pair(i, j);
            }
        }
    }

    vector<vector<int>> distances(n+2, vector<int>(m+2, 0));
    queue<pair<int, int>> candidates;
    vector<vector<bool>> visited(n+2, vector<bool>(m+2, false));
    candidates.push(start_point);

    int cnt = 0;
    while(!candidates.empty()) {
        unsigned candidates_size = candidates.size();
        for(unsigned i = 0; i < candidates_size; i++) {
            pair<int, int> cur_pos = candidates.front();
            candidates.pop();
            if(!visited[cur_pos.first][cur_pos.second]) {
                distances[cur_pos.first][cur_pos.second] = cnt;
                visited[cur_pos.first][cur_pos.second] = true;

                vector<pair<int, int>> neighbors = get_neighbors(map, cur_pos);
                for(pair<int, int> neighbor: neighbors) {
                    if (!visited[neighbor.first][neighbor.second]) {
                        candidates.push(neighbor);
                    }
                }
            }
        }
        cnt++;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int distance = distances[i][j];
            bool is_available = (map[i][j] == 1);
            if(distance != 0) {
                cout << distance << " ";
            }
            else if(is_available) {
                cout << -1 << " ";
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}