#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int shortest_paths[100001];
    fill_n(shortest_paths, 100001, INT_MAX);
    shortest_paths[n] = 0;

    int num_duplicated_paths[100001];
    fill_n(num_duplicated_paths, 100001, 0);
    num_duplicated_paths[n] = 1;

    queue<int> candidates;
    candidates.push(n);

    while(!candidates.empty()) {
        int cur_pos = candidates.front();
        candidates.pop();
        if(cur_pos - 1 >= 0 && shortest_paths[cur_pos] + 1 <= shortest_paths[cur_pos - 1]) {
            candidates.push(cur_pos - 1);
            shortest_paths[cur_pos - 1] = shortest_paths[cur_pos] + 1;
            num_duplicated_paths[cur_pos - 1]++;
        }
        if(cur_pos + 1 < 100001 && shortest_paths[cur_pos] + 1 <= shortest_paths[cur_pos + 1]) {
            candidates.push(cur_pos + 1);
            shortest_paths[cur_pos + 1] = shortest_paths[cur_pos] + 1;
            num_duplicated_paths[cur_pos + 1]++;
        }
        if(cur_pos * 2 < 100001 && shortest_paths[cur_pos] + 1 <= shortest_paths[cur_pos * 2]) {
            candidates.push(cur_pos * 2);
            shortest_paths[cur_pos * 2] = shortest_paths[cur_pos] + 1;
            num_duplicated_paths[cur_pos * 2]++;
        }
    }

    printf("%d\n%d", shortest_paths[k], num_duplicated_paths[k]);

    return 0;
}