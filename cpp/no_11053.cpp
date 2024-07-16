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

    vector<int> LIS(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (items[i] > items[j]) {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }

    cout << *ranges::max_element(LIS.begin(), LIS.end());

    return 0;
}
