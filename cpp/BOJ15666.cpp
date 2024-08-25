#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void bt(set<vector<int>>& memo, const vector<int>& items, vector<int> cur_progression, const int m, const int cur_pos) {
    if(cur_progression.size() == m) {
        ranges::sort(cur_progression.begin(), cur_progression.end());
        memo.insert(cur_progression);
    }
    else {
        for(int i = cur_pos; i < items.size(); i++) {
            cur_progression.push_back(items[i]);
            bt(memo, items, cur_progression, m, i);
            cur_progression.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> items(n);
    for(int& item: items) {
        cin >> item;
    }

    set<vector<int>> memo;
    bt(memo, items, vector<int>(0), m, 0);

    for(const vector<int>& progression: memo) {
        for(const int& item: progression) {
            printf("%d ", item);
        }
        printf("\n");
    }

    return 0;
}