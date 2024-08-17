#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>

#define DUMMY_ROOT (-1)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int shortest_path_lens[100001];
    fill_n(shortest_path_lens, 100001, INT_MAX);
    shortest_path_lens[n] = 0;

    int parents[100001];
    parents[n] = DUMMY_ROOT;

    queue<int> candidates;
    candidates.push(n);

    while(!candidates.empty()) {
        int cur_pos = candidates.front();
        int cur_path_len = shortest_path_lens[cur_pos];
        candidates.pop();
        if(cur_pos * 2 < 100001 && cur_path_len + 1 < shortest_path_lens[cur_pos * 2]) {
            candidates.push(cur_pos * 2);
            shortest_path_lens[cur_pos * 2] = cur_path_len + 1;
            parents[cur_pos * 2] = cur_pos;
        }
        if(cur_pos + 1 < 100001 && cur_path_len + 1 < shortest_path_lens[cur_pos + 1]) {
            candidates.push(cur_pos + 1);
            shortest_path_lens[cur_pos + 1] = cur_path_len + 1;
            parents[cur_pos + 1] = cur_pos;
        }
        if(cur_pos - 1 >= 0 && cur_path_len + 1 < shortest_path_lens[cur_pos - 1]) {
            candidates.push(cur_pos - 1);
            shortest_path_lens[cur_pos - 1] = cur_path_len + 1;
            parents[cur_pos - 1] = cur_pos;
        }
    }

    int cur_pos = k;
    stack<int> shortest_path;
    while(cur_pos != n) {
        shortest_path.push(cur_pos);
        cur_pos = parents[cur_pos];
    }
    shortest_path.push(n);

    printf("%d\n", shortest_path_lens[k]);
    while(!shortest_path.empty()) {
        printf("%d ", shortest_path.top());
        shortest_path.pop();
    }

    return 0;
}