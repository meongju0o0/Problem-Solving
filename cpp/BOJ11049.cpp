#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int get_min_mul(const vector<vector<int>>& mat_sizes) {
    const size_t n = mat_sizes.size();
    vector<vector<int>> memo(n, vector<int>(n, 0));

    for(int diag = 1; diag < n; diag++) {
        for(int i = 0; i < n - diag; i++) {
            const int j = i + diag;
            int min_mul = INT_MAX;
            for(int k = i; k < j; k++) {
                min_mul = min(min_mul, memo[i][k] + memo[k+1][j] + mat_sizes[i][0] * mat_sizes[k][1] * mat_sizes[j][1]);
            }
            memo[i][j] = min_mul;
        }
    }

    return memo[0][n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> mat_sizes(n, vector<int>(2));

    for(vector<int>& mat_size: mat_sizes) {
        cin >> mat_size[0] >> mat_size[1];
    }

    printf("%d", get_min_mul(mat_sizes));

    return 0;
}