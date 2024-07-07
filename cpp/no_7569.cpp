#include <iostream>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

void push_changeable(vector<vector<vector<int>>>& boxes, queue<tuple<int, int, int>>& riped_queue, tuple<int, int, int>& cur_tomato) {
    int i = get<0>(cur_tomato);
    int j = get<1>(cur_tomato);
    int k = get<2>(cur_tomato);

    if (boxes[i-1][j][k] == 0) {
        riped_queue.emplace(i-1, j, k);
        boxes[i-1][j][k] = 1;
    }
    if (boxes[i+1][j][k] == 0) {
        riped_queue.emplace(i+1, j, k);
        boxes[i+1][j][k] = 1;
    }
    if (boxes[i][j-1][k] == 0) {
        riped_queue.emplace(i, j-1, k);
        boxes[i][j-1][k] = 1;
    }
    if (boxes[i][j+1][k] == 0) {
        riped_queue.emplace(i, j+1, k);
        boxes[i][j+1][k] = 1;
    }
    if (boxes[i][j][k-1] == 0) {
        riped_queue.emplace(i, j, k-1);
        boxes[i][j][k-1] = 1;
    }
    if (boxes[i][j][k+1] == 0) {
        riped_queue.emplace(i, j, k+1);
        boxes[i][j][k+1] = 1;
    }
}

bool is_all_riped(vector<vector<vector<int>>>& boxes, int h, int n, int m) {
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (boxes[i][j][k] == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Variable Initialize
    int m, n, h;
    cin >> m >> n >> h;
    vector<vector<vector<int>>> boxes(h+2, vector<vector<int>>(n+2, vector<int>(m+2, -1)));
    // struct: boxes[h][n][m]: m열 n행 h층 박스

    queue<tuple<int, int, int>> already_riped;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                cin >> boxes[i][j][k];
                if (boxes[i][j][k] == 1) {
                    already_riped.emplace(i, j, k);
                }
            }
        }
    }

    // Calculate days
    int days = -1;
    while (!already_riped.empty()) {
        days++;
        unsigned current_level_size = already_riped.size();
        for (int i = 0; i < current_level_size; i++) {
            tuple<int, int, int> cur_tomato = already_riped.front();
            already_riped.pop();
            push_changeable(boxes, already_riped, cur_tomato);
        }
    }

    // Print results
    if (is_all_riped(boxes, h, n, m)) {
        cout << days;
    } else {
        cout << -1;
    }

    return 0;
}
