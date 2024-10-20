#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> items(n + 1, 0);
    vector<int> acc(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> items[i];
        acc[i] = acc[i - 1] + items[i];
    }

    vector<int> dp(n + 1, -1001);
    vector<int> idx(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        if(acc[i] - acc[idx[i - 1]] > dp[i - 1]) {
            dp[i] = acc[i] - acc[idx[i - 1]];
        }
        else {
            dp[i] = dp[i - 1];
        }
        if(acc[i] < acc[idx[i - 1]]) {
            idx[i] = i;
        }
        else {
            idx[i] = idx[i - 1];
        }
    }

    printf("%d", dp.back());

    return 0;
}