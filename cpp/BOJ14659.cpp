#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> items(n);
    for (int& item : items) {
        cin >> item;
    }

    int max_cnt = 0;
    int cnt = 0;
    int max_height = 0; 

    for (int i = 0; i < n; i++) {
        if (items[i] > max_height) {
            max_height = items[i];
            cnt = 0;
        } else {
            cnt++;
            max_cnt = max(max_cnt, cnt);
        }
    }
    cout << max_cnt << endl;

    return 0;
}