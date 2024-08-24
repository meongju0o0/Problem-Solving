#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> items(n);
    for (int& item : items) {
        cin >> item;
    }

    vector<int> LIS(n, 1), LDS(n, 1); // memoization

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (items[i] > items[j]) {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (items[i] > items[j]) {
                LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }
    }

    int max_bitonic_length = 0;
    for (int i = 0; i < n; i++) {
        max_bitonic_length = max(max_bitonic_length, LIS[i] + LDS[i] - 1);
    }

    cout << max_bitonic_length;

    return 0;
}
