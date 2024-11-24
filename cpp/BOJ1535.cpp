#include <iostream>
#include <vector>
#include <unordered_map>
#include <ranges>
#include <algorithm>

#define KEY_MUL 100

using namespace std;

inline int make_key(const int a, const int b) {
    return a * KEY_MUL + b;
}

int delgiht_sack(unordered_map<int, int>& memo, const vector<pair<int, int>>& items, const int n, const int k) {
    const int key = make_key(n, k);
    if(memo.contains(key)) {
        return memo[key];
    }
    else if(n == 0 || k <= 1) {
        return 0;
    }
    else {
        const int cur_stamina = items[n - 1].first;
        const int cur_delgiht = items[n - 1].second;

        if(cur_stamina < k) {
            memo[key] = max(delgiht_sack(memo, items, n - 1, k), cur_delgiht + delgiht_sack(memo, items, n - 1, k - cur_stamina));
        }
        else {
            memo[key] = delgiht_sack(memo, items, n - 1, k);
        }

        return memo[key];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> items(n);

    for(int& stamina: views::keys(items)) cin >> stamina;
    for(int& delight: views::values(items)) cin >> delight;

    unordered_map<int, int> memo;

    printf("%d", delgiht_sack(memo, items, n, 100));

    return 0;
}