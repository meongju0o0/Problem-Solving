#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long dtype;

dtype dp(unordered_map<dtype, dtype>& memo, const dtype n, const dtype p, const dtype q, const dtype x, const dtype y) {
    if(n < 1) {
        return 1;
    }
    else if(memo.contains(n)) {
        return memo[n];
    }
    else {
        memo[n] = dp(memo, n / p - x, p, q, x, y) + dp(memo, n / q - y, p, q, x, y);
        return memo[n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dtype n, p, q, x, y;
    cin >> n >> p >> q >> x >> y;

    unordered_map<dtype, dtype> memo;

    printf("%lld", dp(memo, n, p, q, x, y));

    return 0;
}