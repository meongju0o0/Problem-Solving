#include <iostream>
#include <unordered_map>

#define MOD 10007

using namespace std;

int dp(const int n, unordered_map<int, int>& memo) {
    if (memo.contains(n)) {
        return memo[n];
    }
    else {
        memo[n] = (dp(n - 1, memo) + 2 * dp(n - 2, memo)) % MOD;
        return memo[n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, int> memo = { {0, 1}, {1, 1} };
    printf("%d", dp(n, memo));

    return 0;
}