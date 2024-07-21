#include <iostream>
#include <vector>
#include <climits>

using namespace std;

unsigned get_num_cables(const vector<int>& cables, const unsigned& cutting_len) {
    unsigned cnt = 0;
    for(const int& cable: cables) {
        cnt += cable / cutting_len;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    vector<int> cables(k);
    for(int& cable: cables) {
        cin >> cable;
    }

    unsigned left = 1;
    unsigned right = INT_MAX;
    unsigned cutting_len = (left + right) / 2;
    while(left <= right) {
        unsigned num_cables = get_num_cables(cables, cutting_len);
        if(num_cables >= n) {
            left = cutting_len + 1;
        }
        else {
            right = cutting_len - 1;
        }
        cutting_len = (left + right) / 2;
    }

    cout << cutting_len;

    return 0;
}