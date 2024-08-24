#include <iostream>
#include <vector>
#include <set>

using namespace std;

void combination(set<vector<int>>& comb, const vector<int>& cur_comb, const int& pos, const int& n, const int& m) {
    if(cur_comb.size() == m) {
        comb.insert(cur_comb);
    }
    else {
        for(int i = pos; i <= n; i++) {
            vector<int> temp_comb = cur_comb;
            temp_comb.push_back(i);
            combination(comb, temp_comb, i, n, m);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<vector<int>> comb;
    combination(comb, vector<int>(0), 1, n, m);

    for(const vector<int>& temp_comb: comb) {
        for(const int& item: temp_comb) {
            printf("%d ", item);
        }
        printf("\n");
    }

    return 0;
}