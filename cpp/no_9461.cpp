#include <iostream>
#include <unordered_map>

using namespace std;

unsigned long long dp(unordered_map<int, unsigned long long>& memo, const int n) {
    if(memo.contains(n)) {
        return memo[n];
    }
    else {
        memo[n] = dp(memo, n - 5) + dp(memo, n - 1);
        return memo[n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        unordered_map<int, unsigned long long> memo = {
            {1, 1},
            {2, 1},
            {3, 1},
            {4, 2},
            {5, 2}
        };

        printf("%llu\n", dp(memo, n));
    }

    return 0;
}