#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

bool build_cmp (tuple<int, int, int, int>& a, tuple<int, int, int, int> b) {
    if(get<1>(a) < get<1>(b) && get<2>(a) < get<2>(b)) {
        return false;
    }
    else {
        return get<0>(a) > get<0>(b);
    }
}

bool idx_cmp (tuple<int, int, int, int>& a, tuple<int, int, int, int> b) {
    return get<0>(a) < get<0>(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<tuple<int, int, int, int>> table; //(인덱스 id, 몸무게, 키, 순위)
    for(int i = 0; i < n; i++) {
        int weight, height;
        cin >> weight >> height;
        table.emplace_back(i, weight, height, 0);
    }

    sort(table.begin(), table.end(), build_cmp);

    int prev_weight, prev_height, cur_weight, cur_height;
    int idx = 0, rank = 1;
    for(tuple<int, int, int, int>& record: table) {
        if(idx == 0) {
            cur_weight = get<1>(record);
            cur_height = get<2>(record);
            get<3>(record) = rank;
        }
        else {
            prev_weight = cur_weight;
            prev_height = cur_height;
            cur_weight = get<1>(record);
            cur_height = get<2>(record);
            if(prev_weight > cur_weight && prev_height > cur_height) {
                rank = idx + 1;
                get<3>(record) = rank;
            }
            else {
                get<3>(record) = rank;
            }
        }
        idx++;
    }

    sort(table.begin(), table.end(), idx_cmp);

    for(tuple<int, int, int, int>& record: table) {
        printf("%d ", get<3>(record));
    }

    return 0;
}