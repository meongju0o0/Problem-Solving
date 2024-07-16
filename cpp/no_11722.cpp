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

    vector<int> LDS(n, 1);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= i; j--) {
            if (items[i] > items[j]) {
                LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }
    }

    cout << *ranges::max_element(LDS.begin(), LDS.end());

    return 0;
}
