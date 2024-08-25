#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

void bt(set<vector<int>>& memo, const vector<int>& items, vector<int> cur_progression, const int m, unordered_set<int>& visited) {
    if(cur_progression.size() == m) {
        ranges::sort(cur_progression.begin(), cur_progression.end());
        memo.insert(cur_progression);
    }
    else {
        for(int i = 0; i < items.size(); i++) {
            if(!visited.contains(i)) {
                visited.insert(i);
                cur_progression.push_back(items[i]);
                bt(memo, items, cur_progression, m, visited);
                cur_progression.pop_back();
                visited.erase(i);
            }
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
    unordered_set<int> visited;
    bt(memo, items, vector<int>(0), m, visited);

    for(const vector<int>& progression: memo) {
        for(const int& item: progression) {
            printf("%d ", item);
        }
        printf("\n");
    }

    return 0;
}