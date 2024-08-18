#include <iostream>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> items(n);
    map<int, int> mymap;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        items[i] = x;
        mymap[x] = 0;
    }

    int i = 0;
    for(auto& kv: mymap) {
        kv.second = i++;
    }

    for(const int& item: items) {
        printf("%d ", mymap[item]);
    }

    return 0;
}