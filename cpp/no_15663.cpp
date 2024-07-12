#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

void combination(set<vector<int>>& memo, const vector<int>& items, const vector<int>& cur_comb, const unordered_set<int>& visited_ids, const int& n, const int& m) {
    if(cur_comb.size() == m) {
        memo.insert(cur_comb);
    }
    else {
        for(int i = 0; i < n; i++) {
            if(!visited_ids.contains(i)) {
                vector<int> temp_comb = cur_comb;
                unordered_set<int> temp_visited_ids = visited_ids;
                temp_comb.push_back(items[i]);
                temp_visited_ids.insert(i);
                combination(memo, items, temp_comb, temp_visited_ids, n, m);
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
    for(int i = 0; i < n; i++) {
        cin >> items[i];
    }

    set<vector<int>> memo;

    unordered_set<int> visited_item;
    combination(memo, items, vector<int>(0), visited_item, n, m);

    for(const vector<int>& comb: memo) {
        for(const int& cur_comb: comb) {
            printf("%d ", cur_comb);
        }
        printf("\n");
    }

    return 0;
}