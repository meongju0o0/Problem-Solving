#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> items(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> items[i][j];
        }
    }

    vector<vector<int>> memo(n, vector<int>(n, INT_MIN));
    memo[0][0] = items[0][0];
    for(int i = 1; i < n; i++) {
        memo[i][0] = memo[i-1][0] + items[i][0];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= i; j++) {
            if(i == j) {
                memo[i][j] = memo[i-1][j-1] + items[i][j];
            }
            else {
                memo[i][j] = max(memo[i-1][j-1], memo[i-1][j]) + items[i][j];
            }
        }
    }

    printf("%d", *ranges::max_element((memo.end() - 1)->begin(), (memo.end() - 1)->end()));

    return 0;
}