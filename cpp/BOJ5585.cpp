#include <iostream>

using namespace std;

constexpr int rest_set[6] = {500, 100, 50, 10, 5, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    n = 1000 - n;

    const int n_500 = n / rest_set[0];
    const int n_100 = (n - rest_set[0] * n_500) / rest_set[1];
    const int n_50 = (n - (rest_set[0] * n_500 + rest_set[1] * n_100)) / rest_set[2];
    const int n_10 = (n - (rest_set[0] * n_500 + rest_set[1] * n_100 + rest_set[2] * n_50)) / rest_set[3];
    const int n_5 = (n - (rest_set[0] * n_500 + rest_set[1] * n_100 + rest_set[2] * n_50 + rest_set[3] * n_10)) / rest_set[4];
    const int n_1 = n - (rest_set[0] * n_500 + rest_set[1] * n_100 + rest_set[2] * n_50 + rest_set[3] * n_10 + rest_set[4] * n_5);

    printf("%d", n_500 + n_100 + n_50 + n_10 + n_5 + n_1);

    return 0;
}