#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> memo(n, vector<int>(k, 1));

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < min(i, k); j++) {
            memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
        }
    }

    printf("%d", memo[n-1][k-1]);

    return 0;
}