#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int cur_item;
    int cur_idx = 1, cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> cur_item;
        if (cur_idx != cur_item) {
            cnt++;
        } else {
            cur_idx++;
        }
    }

    cout << cnt << '\n';

    return 0;
}