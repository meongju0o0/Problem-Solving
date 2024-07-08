#include <iostream>
#include <tuple>
#include <set>

using namespace std;

struct cmp {
    bool operator() (const tuple<int, int>& a, const tuple<int, int>& b) const {
        if(get<0>(a) != get<0>(b)) {
            return get<0>(a) < get<0>(b);
        }
        else {
            return get<1>(a) < get<1>(b);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<tuple<int, int>, cmp> coordinates;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coordinates.emplace(x, y);
    }

    for(auto& coordinate: coordinates) {
        printf("%d %d \n", get<0>(coordinate), get<1>(coordinate));
    }

    return 0;
}