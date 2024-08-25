#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class MaxSegmentTree {
private:
    vector<int> tree;
    int num_items;

public:
    MaxSegmentTree(int _num_items, const vector<int>& data) {
        num_items = _num_items;
        tree.resize(2 * num_items);
        for (int i = 0; i < num_items; i++) {
            tree[num_items + i] = data[i];
        }
        for (int i = num_items - 1; i > 0; i--) {
            tree[i] = ranges::max(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void update_item(int item_idx, int new_val) {
        int pos = num_items + item_idx - 1;
        tree[pos] = new_val;
        while (pos > 1) {
            pos /= 2;
            tree[pos] = ranges::max(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

    [[nodiscard]] int get_max_query(int start_idx, int end_idx) const {
        int cur_start_idx = num_items + start_idx - 1;
        int cur_end_idx = num_items + end_idx - 1;
        int max = INT_MIN;

        while (cur_start_idx <= cur_end_idx) {
            if (cur_start_idx % 2 == 1) {
                max = ranges::max(max, tree[cur_start_idx++]);
            }
            if (cur_end_idx % 2 == 0) {
                max = ranges::max(max, tree[cur_end_idx--]);
            }
            cur_start_idx /= 2;
            cur_end_idx /= 2;
        }

        return max;
    }
};

class MinSegmentTree {
private:
    vector<int> tree;
    int num_items;

public:
    MinSegmentTree(int _num_items, const vector<int>& data) {
        num_items = _num_items;
        tree.resize(2 * num_items);
        for (int i = 0; i < num_items; i++) {
            tree[num_items + i] = data[i];
        }
        for (int i = num_items - 1; i > 0; i--) {
            tree[i] = ranges::min(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void update_item(int item_idx, int new_val) {
        int pos = num_items + item_idx - 1;
        tree[pos] = new_val;
        while (pos > 1) {
            pos /= 2;
            tree[pos] = ranges::min(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

    [[nodiscard]] int get_min_query(int start_idx, int end_idx) const {
        int cur_start_idx = num_items + start_idx - 1;
        int cur_end_idx = num_items + end_idx - 1;
        int min = INT_MAX;

        while (cur_start_idx <= cur_end_idx) {
            if (cur_start_idx % 2 == 1) {
                min = ranges::min(min, tree[cur_start_idx++]);
            }
            if (cur_end_idx % 2 == 0) {
                min = ranges::min(min, tree[cur_end_idx--]);
            }
            cur_start_idx /= 2;
            cur_end_idx /= 2;
        }

        return min;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> items(n);
    for(int& item: items) {
        cin >> item;
    }

    MaxSegmentTree max_seg_tree(n, items);
    MinSegmentTree min_seg_tree(n, items);

    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        printf("%d %d\n", min_seg_tree.get_min_query(a, b), max_seg_tree.get_max_query(a, b));
    }

    return 0;
}