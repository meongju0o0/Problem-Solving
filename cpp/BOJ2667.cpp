#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define COO_MUL 1000

inline int make_coo(const int y, const int x) {
    return y * COO_MUL + x;
}

inline int get_y(const int coo) {
    return coo / COO_MUL;
}

inline int get_x(const int coo) {
    return coo % COO_MUL;
}

int get_start_pos(const vector<vector<int>>& map, const int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(map[i][j] == 1) {
                return make_coo(i, j);
            }
        }
    }
    return make_coo(-1, -1);
}

void push_neighbors(vector<vector<int>>& map, queue<int>& cands, const int y, const int x) {
    if(map[y - 1][x]) {
        cands.push(make_coo(y - 1, x));
    }
    if(map[y + 1][x]) {
        cands.push(make_coo(y + 1, x));
    }
    if(map[y][x - 1]) {
        cands.push(make_coo(y, x - 1));
    }
    if(map[y][x + 1]) {
        cands.push(make_coo(y, x + 1));
    }
}

vector<int> num_apts(vector<vector<int>>& map, const int n) {
    vector<int> num_houses;
    queue<int> cands;

    while(true) {
        int start_pos = get_start_pos(map, n);
        if(start_pos == make_coo(-1, -1)) {
            break;
        }
        else {
            int num_house = 0;
            cands.push(start_pos);
            while(!cands.empty()) {
                const int cur_pos = cands.front();
                cands.pop();
                const int x_pos = get_x(cur_pos);
                const int y_pos = get_y(cur_pos);
                if(map[y_pos][x_pos]) {
                    map[y_pos][x_pos] = 0;
                    num_house++;
                    push_neighbors(map, cands, y_pos, x_pos);
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
            map[i][j] = line[j - 1] - '0';
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
