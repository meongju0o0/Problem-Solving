#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sum_candy = 0;
    int odd_cnt = 0;
    int min_odd_candy = INT_MAX;
    for (int i = 0; i < n; i++) {
        int candy = 0;
        cin >> candy;
        sum_candy += candy;
        if (candy % 2 == 1) {
            odd_cnt++;
            min_odd_candy = min(min_odd_candy, candy);
        }
    }

    if (odd_cnt % 2 == 1) {
        sum_candy -= min_odd_candy;
    }

    printf("%d", sum_candy);

    return 0;
}