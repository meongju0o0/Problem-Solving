#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 10007

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> memo(n + 1, vector<int>(k + 1));

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= min(i, k); j++) {
            if(j == 0 || j == i) {
                memo[i][j] = 1;
            }
            else {
                memo[i][j] = (memo[i-1][j-1] + memo[i-1][j]) % MOD;
            }
        }
    }

    printf("%d\n", memo[n][k]);

    return 0;
}