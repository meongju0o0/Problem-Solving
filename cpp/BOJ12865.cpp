#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define KEY_MUL 1000000

using namespace std;

inline int make_key(const int n, const int k) {
    return n * KEY_MUL + k;
}

int knapsack(const vector<pair<int, int>>& items, unordered_map<int, int>& memo, const int n, const int k) {
    const int key = make_key(n, k);
    if(memo.contains(key)) {
        return memo[key];
    }
    else if(n == 0 || k == 0) {
        return 0;
    }
    else {
        const int cur_weight = items[n - 1].first;
        const int cur_value = items[n - 1].second;
        if(cur_weight <= k) {
            memo[key] = max(knapsack(items, memo, n - 1, k), cur_value + knapsack(items, memo, n - 1, k - cur_weight));
        }
        else {
            memo[key] = knapsack(items, memo, n - 1, k);
        }
        return memo[key];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> items(n);

    for(pair<int, int>& item: items) {
        cin >> item.first >> item.second;
    }

    unordered_map<int, int> memo;

    printf("%d", knapsack(items, memo, n, k));

    return 0;
}