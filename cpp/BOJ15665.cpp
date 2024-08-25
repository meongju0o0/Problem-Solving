#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void bt(set<vector<int>>& memo, const vector<int>& items, vector<int> cur_progression, const int m) {
    if(cur_progression.size() == m) {
        memo.insert(cur_progression);
    }
    else {
        for(int i = 0; i < items.size(); i++) {
            cur_progression.push_back(items[i]);
            bt(memo, items, cur_progression, m);
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
    ranges::sort(items.begin(), items.end());

    set<vector<int>> memo;
    bt(memo, items, vector<int>(0), m);

    for(const vector<int>& progression: memo) {
        for(const int& item: progression) {
            printf("%d ", item);
        }
        printf("\n");
    }

    return 0;
}