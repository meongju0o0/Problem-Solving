#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    int num_items;

public:
    SegmentTree(int _num_items, const vector<long long>& data) {
        num_items = _num_items;
        tree.resize(2 * num_items);
        for (int i = 0; i < num_items; i++) {
            tree[num_items + i] = data[i];
        }
        for (int i = num_items - 1; i > 0; i--) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

    void updateItem(int item_idx, long long new_val) {
        int pos = num_items + item_idx - 1;
        tree[pos] = new_val;
        while (pos > 1) {
            pos /= 2;
            tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
        }
    }

    [[nodiscard]] long long get_sum_query(int start_idx, int end_idx) const {
        int cur_start_idx = num_items + start_idx - 1;
        int cur_end_idx = num_items + end_idx - 1;
        long long sum = 0;

        while (cur_start_idx <= cur_end_idx) {
            if (cur_start_idx % 2 == 1) {
                sum += tree[cur_start_idx++];
            }
            if (cur_end_idx % 2 == 0) {
                sum += tree[cur_end_idx--];
            }
            cur_start_idx /= 2;
            cur_end_idx /= 2;
        }

        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> data(n);
    for(int i = 0; i < n; i++) {
        cin >> data[i];
    }

    SegmentTree seg_tree(n, data);

    string result;
    int a, b;
    long long c;
    for(int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            seg_tree.updateItem(b, c);
        }
        else if (a == 2) {
            printf("%lld\n", seg_tree.get_sum_query(b, c));
        }
    }

    cout << result;

    return 0;
}
