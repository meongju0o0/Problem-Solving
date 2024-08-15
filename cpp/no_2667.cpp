#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

tuple<int, int> get_start_pos(const vector<vector<int>>& map, const int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(map[i][j] == 1) {
                return make_tuple(i, j);
            }
        }
    }
    return make_tuple(-1, -1);
}

vector<int> num_apts(vector<vector<int>>& map, const int n) {
    vector<int> num_houses;
    queue<tuple<int, int>> candidates;

    while(true) {
        tuple<int, int> start_pos = get_start_pos(map, n);
        if(start_pos == make_tuple(-1, -1)) {
            break;
        }
        else {
            int num_house = 0;
            candidates.push(start_pos);
            while(!candidates.empty()) {
                tuple<int, int> cur_pos = candidates.front();
                candidates.pop();
                const int x_pos = get<0>(cur_pos);
                const int y_pos = get<1>(cur_pos);
                if(map[x_pos][y_pos]) {
                    map[x_pos][y_pos] = 0;
                    num_house++;
                    if(map[x_pos - 1][y_pos]) {
                        candidates.emplace(x_pos - 1, y_pos);
                    }
                    if(map[x_pos + 1][y_pos]) {
                        candidates.emplace(x_pos + 1, y_pos);
                    }
                    if(map[x_pos][y_pos - 1]) {
                        candidates.emplace(x_pos, y_pos - 1);
                    }
                    if(map[x_pos][y_pos + 1]) {
                        candidates.emplace(x_pos, y_pos + 1);
                    }
                }
            }
            num_houses.push_back(num_house);
        }
    }

    return num_houses;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> map(n + 2, vector<int>(n + 2, 0));

    for(int i = 1; i <= n; i++) {
        string line;
        cin >> line;
        for(int j = 1; j <= n; j++) {
            map[i][j] = line.front() - '0';
            line.erase(line.begin());
        }
    }

    vector<int> num_houses = num_apts(map, n);
    ranges::sort(num_houses.begin(), num_houses.end());

    printf("%llu\n", num_houses.size());
    for(const int& num_house: num_houses) {
        printf("%d\n", num_house);
    }

    return 0;
}