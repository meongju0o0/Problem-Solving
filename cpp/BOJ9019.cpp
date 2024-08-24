#include <iostream>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int a, b;
        cin >> a >> b;

        queue<int> candidates;
        int path_lens[10000];
        fill_n(path_lens, 10000, INT_MAX);
        tuple<int, char> parents[10000];

        candidates.push(a);
        path_lens[a] = 0;
        parents[a] = make_tuple(-1, 'E');

        while(!candidates.empty()) {
            int cur_state, next_state;
            cur_state = candidates.front();
            candidates.pop();
            next_state = (cur_state * 2) % 10000;
            if(path_lens[cur_state] + 1 < path_lens[next_state]) {
                candidates.push(next_state);
                path_lens[next_state] = path_lens[cur_state] + 1;
                parents[next_state] = make_tuple(cur_state, 'D');
            }
            next_state = (cur_state == 0) ? 9999 : cur_state - 1;
            if(path_lens[cur_state] + 1 < path_lens[next_state]) {
                candidates.push(next_state);
                path_lens[next_state] = path_lens[cur_state] + 1;
                parents[next_state] = make_tuple(cur_state, 'S');
            }
            next_state = (cur_state % 1000) * 10 + cur_state / 1000;
            if(path_lens[cur_state] + 1 < path_lens[next_state]) {
                candidates.push(next_state);
                path_lens[next_state] = path_lens[cur_state] + 1;
                parents[next_state] = make_tuple(cur_state, 'L');
            }
            next_state = (cur_state % 10) * 1000 + cur_state / 10;
            if(path_lens[cur_state] + 1 < path_lens[next_state]) {
                candidates.push(next_state);
                path_lens[next_state] = path_lens[cur_state] + 1;
                parents[next_state] = make_tuple(cur_state, 'R');
            }
        }

        stack<char> result_stack;
        int cur_state = b;
        while(get<1>(parents[cur_state]) != 'E') {
            result_stack.push(get<1>(parents[cur_state]));
            cur_state = get<0>(parents[cur_state]);
        }

        while(!result_stack.empty()) {
            printf("%c", result_stack.top());
            result_stack.pop();
        }
        printf("\n");
    }

    return 0;
}