#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> seq(n+1, INT_MAX);
    vector<int> memo(n+1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> seq[i];
    }

    for(int i = 1; i <= n; i++) {
        priority_queue<int> idx_queue;
        for(int j = 0; j < i; j++) {
            if(seq[i] < seq[j]) {
                idx_queue.push(memo[j]);
            }
        }
        memo[i] = idx_queue.top() + 1;
    }

    cout << *ranges::max_element(memo.begin(), memo.end());

    return 0;
}