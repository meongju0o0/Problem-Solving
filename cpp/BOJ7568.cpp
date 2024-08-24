#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> table; //(몸무게, 키, 순위)
    for(int i = 0; i < n; i++) {
        int weight, height;
        cin >> weight >> height;
        table.emplace_back(weight, height, 0);
    }

    for(tuple<int, int, int>& record: table) {
        int rank = 1;
        for(tuple<int, int, int> temp_record: table) {
            if(get<0>(record) < get<0>(temp_record) && get<1>(record) < get<1>(temp_record)) {
                rank++;
            }
        }
        get<2>(record) = rank;
    }

    for(tuple<int, int, int>& record: table) {
        printf("%d ", get<2>(record));
    }

    return 0;
}