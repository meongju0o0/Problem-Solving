#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> sticks(n);

    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }

    int push_cnt = 0;
    bool is_prev_larger = false;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            if (!is_prev_larger) {
                push_cnt++;
            }
            sticks[i] = 0;
        }
        else {
            if (!is_prev_larger) {
                push_cnt++;
            }
            is_prev_larger = sticks[i] > sticks[i + 1];
            sticks[i] = 0;
        }
    }

    printf("%d", push_cnt);

    return 0;
}