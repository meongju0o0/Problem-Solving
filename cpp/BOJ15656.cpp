#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bt(const int m, const vector<int>& items, vector<int> cur_progression) {
    if(cur_progression.size() == m) {
        for(const int& item: cur_progression) {
            printf("%d ", item);
        }
        printf("\n");
    }
    else {
        for(const int& item: items) {
            cur_progression.push_back(item);
            bt(m, items, cur_progression);
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

    bt(m, items, vector<int>(0));

    return 0;
}