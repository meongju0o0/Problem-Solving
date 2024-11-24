#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define KEY_MUL 100000

using namespace std;

inline int make_key(const int n, const int k) {
    return n * KEY_MUL + k;
}

int study_sack(const vector<pair<int, int>>& items, unordered_map<int, int>& memo, const int n, const int t) {
    const int key = make_key(n, t);
    if(memo.contains(key)) {
        return memo[key];
    }
    else if(n == 0 || t == 0) {
        return 0;
    }
    else {
        const int cur_weight = items[n - 1].first;
        const int cur_value = items[n - 1].second;
        if(cur_weight <= t) {
            memo[key] = max(study_sack(items, memo, n - 1, t), cur_value + study_sack(items, memo, n - 1, t - cur_weight));
        }
        else {
            memo[key] = study_sack(items, memo, n - 1, t);
        }
        return memo[key];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<pair<int, int>> items(n);

    for(pair<int, int>& item: items) {
        cin >> item.first >> item.second;
    }

    unordered_map<int, int> memo;

    printf("%d", study_sack(items, memo, n, t));

    return 0;
}