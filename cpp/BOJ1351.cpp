#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long dtype;

dtype dp(unordered_map<dtype, dtype>& memo, const dtype n, const dtype p, const dtype q) {
    if(memo.contains(n)) {
        return memo[n];
    }
    else {
        memo[n] = dp(memo, n / p, p, q) + dp(memo, n / q, p, q);
        return memo[n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dtype n, p, q;
    cin >> n >> p >> q;

    unordered_map<dtype, dtype> memo;
    memo[0] = 1;

    printf("%lld", dp(memo, n, p, q));

    return 0;
}