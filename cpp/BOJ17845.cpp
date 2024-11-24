#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <cstring>

using namespace std;

int items[1000][2];
int memo[10001][1001];

int subject_sack(const int n, const int k) {
    if(memo[n][k] != -1) {
        return memo[n][k];
    }

    if(n == 0 || k == 0) {
        return memo[n][k] = 0;
    }
    else {
        const int cur_importance = items[k - 1][0];
        const int cur_time = items[k - 1][1];

        if(cur_time <= n) {
            memo[n][k] = max(subject_sack(n, k - 1), cur_importance + subject_sack(n - cur_time, k - 1));
        }
        else {
            memo[n][k] = subject_sack(n, k - 1);
        }

        return memo[n][k];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        cin >> items[i][0] >> items[i][1];
    }

    memset(memo, -1, sizeof(int) * 10001 * 1001);

    printf("%d", subject_sack(n, k));

    return 0;
}