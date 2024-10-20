#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<long long>> costs(n, vector<long long>(3));

    for(int i = 0; i < n; i++) {
        cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
    }

    vector<vector<long long>> dp(n, vector<long long>(3));

    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];

    for(int i = 1; i < n; i++) {
        dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }

    printf("%lld", min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}));

    return 0;
}
