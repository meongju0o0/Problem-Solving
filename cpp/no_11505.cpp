#include <iostream>
#include <vector>
#include <string>

#define MOD 1000000007

using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    int num_items;

public:
    SegmentTree(int _num_items, const vector<long long>& data) {
        num_items = _num_items;
        tree.resize(2 * num_items, 1);
        for (int i = 0; i < num_items; i++) {
            tree[num_items + i] = data[i];
        }
        for (int i = num_items - 1; i > 0; i--) {
            tree[i] = (tree[2 * i] * tree[2 * i + 1]) % MOD;
        }
    }

    void update_item(int item_idx, long long new_val) {
        int pos = num_items + item_idx - 1;
        tree[pos] = new_val % MOD;
        while (pos > 1) {
            pos /= 2;
            tree[pos] = (tree[2 * pos] * tree[2 * pos + 1]) % MOD;
        }
    }

    [[nodiscard]] long long get_mul_query(int start_idx, int end_idx) const {
        int cur_start_idx = num_items + start_idx - 1;
        int cur_end_idx = num_items + end_idx - 1;
        long long mul = 1;

        while (cur_start_idx <= cur_end_idx) {
            if (cur_start_idx % 2 == 1) {
                mul = (mul * tree[cur_start_idx++]) % MOD;
            }
            if (cur_end_idx % 2 == 0) {
                mul = (mul * tree[cur_end_idx--]) % MOD;
            }
            cur_start_idx /= 2;
            cur_end_idx /= 2;
        }

        return mul;
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
            seg_tree.update_item(b, c);
        }
        else if (a == 2) {
            printf("%lld\n", seg_tree.get_mul_query(b, c) % MOD);
        }
    }

    return 0;
}
