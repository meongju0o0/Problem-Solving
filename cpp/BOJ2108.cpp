#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> myvec(n);
    unordered_map<int, int> mymap;

    for(int i = 0; i < n; i++) {
        int item;
        cin >> item;
        myvec[i] = item;
        if(mymap.contains(item)) {
            mymap[item]++;
        }
        else {
            mymap[item] = 0;
        }
    }

    sort(myvec.begin(), myvec.end());

    double sum = 0;
    for(const int& item: myvec) {
        sum += item;
    }
    int avg = floor(sum/myvec.size()+0.5);
    int median = myvec[static_cast<int>(myvec.size()/2)];

    int histo = INT_MIN;
    for(const auto& kv_pair: mymap) {
        if(histo < kv_pair.second) {
            histo = kv_pair.second;
        }
    }
    set<int> modes;
    for(const auto& kv_pair: mymap) {
        if(kv_pair.second == histo) {
            modes.insert(kv_pair.first);
        }
    }
    int mode;
    if(modes.size() == 1) {
        mode = *modes.begin();
    }
    else {
        mode = *(++modes.begin());
    }

    int range = abs(*myvec.begin() - *(--myvec.end()));

    printf("%d\n%d\n%d\n%d", avg, median, mode, range);

    return 0;
}