#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

void bt(set<vector<int>>& memo, const int m, const vector<int>& items, vector<int> cur_progression, unordered_set<int>& visited) {
    if(cur_progression.size() == m) {
        ranges::sort(cur_progression.begin(), cur_progression.end());
        memo.insert(cur_progression);
    }
    else {
        for(const int& item: items) {
            if(!visited.contains(item)) {
                visited.insert(item);
                cur_progression.push_back(item);
                bt(memo, m, items, cur_progression, visited);
                cur_progression.pop_back();
                visited.erase(item);
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
    bt(memo, m, items, vector<int>(0), visited);

    for(const vector<int>& progression: memo) {
        for(const int& item: progression) {
            printf("%d ", item);
        }
        printf("\n");
    }

    return 0;
}