#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a_vec(n);
    vector<int> b_vec(n);

    for (int& item: a_vec) {
        cin >> item;
    }
    for (int& item: b_vec) {
        cin >> item;
    }

    int diff_sum = 0;
    for (int i = 0; i < n; i++) {
        if (a_vec[i] > b_vec[i]) {
            diff_sum += a_vec[i] - b_vec[i];
        }
    }

    printf("%d", diff_sum);

    return 0;
}