#include <iostream>
#include <unordered_map>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<int, int> ladders;
    unordered_map<int, int> snakes;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ladders[x-1] = y-1;
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        snakes[u-1] = v-1;
    }

    int shortest_paths[100];
    fill_n(shortest_paths, 100, INT_MAX);
    shortest_paths[0] = 0;

    queue<int> candidates;
    candidates.push(0);

    while(!candidates.empty()) {
        int cur_pos = candidates.front();
        candidates.pop();
        for(int i = 1; i <= 6; i++) {
            if(cur_pos + i < 100 && shortest_paths[cur_pos] + 1 < shortest_paths[cur_pos + i]) {
                int next_pos = cur_pos + i;
                shortest_paths[next_pos] = shortest_paths[cur_pos] + 1;

                if(ladders.contains(next_pos)) {
                    candidates.push(ladders[next_pos]);
                    if(shortest_paths[cur_pos] + 1 < shortest_paths[ladders[next_pos]]) {
                        shortest_paths[ladders[next_pos]] = shortest_paths[cur_pos] + 1;
                    }
                }
                else if(snakes.contains(next_pos)) {
                    candidates.push(snakes[next_pos]);
                    if(shortest_paths[cur_pos] + 1 < shortest_paths[snakes[next_pos]]) {
                        shortest_paths[snakes[next_pos]] = shortest_paths[cur_pos] + 1;
                    }
                }
                else {
                    candidates.push(next_pos);
                }
            }
        }
    }

    cout << shortest_paths[99];

    return 0;
}