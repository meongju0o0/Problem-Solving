#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, b;
    cin >> n >> m >> b;

    vector<vector<int>> map(n, vector<int>(m));
    int max_height = INT_MIN;
    int min_height = INT_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] > max_height) {
                max_height = map[i][j];
            }
            if(map[i][j] < min_height) {
                min_height = map[i][j];
            }
        }
    }

    pair<int, int> min_time = make_pair(INT_MAX, -1);

    for(int target_height = min_height; target_height <= max_height; target_height++) {
        int temp_b = b;
        int temp_time = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cur_height = map[i][j];
                if(cur_height < target_height) {
                    int sub = target_height - cur_height;
                    temp_b -= sub;
                    temp_time += sub;
                }
                else if(cur_height > target_height) {
                    int sub = cur_height - target_height;
                    temp_b += sub;
                    temp_time += 2 * sub;
                }
            }
        }

        if (temp_b >= 0) {
            if (temp_time < min_time.first) {
                min_time.first = temp_time;
                min_time.second = target_height;
            }
            else if (temp_time == min_time.first && target_height > min_time.second) {
                min_time.second = target_height;
            }
        }
    }

    printf("%d %d", min_time.first, min_time.second);

    return 0;
}