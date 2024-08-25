#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bt(const int m, const vector<int>& items, vector<int> cur_progression, const int cur_pos) {
    if(cur_progression.size() == m) {
        for(const int& item: cur_progression) {
            printf("%d ", item);
        }
        printf("\n");
    }
    else {
        for(int i = cur_pos; i < items.size(); i++) {
            cur_progression.push_back(items[i]);
            bt(m, items, cur_progression, i);
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

    bt(m, items, vector<int>(0), 0);

    return 0;
}