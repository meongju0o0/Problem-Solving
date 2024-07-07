#include <iostream>
#include <vector>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> prefix_sum(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        prefix_sum[i] = prefix_sum[i - 1] + num;
    }

    string result;
    for(int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        result += to_string(prefix_sum[end] - prefix_sum[start - 1]) + "\n";
    }

    cout << result;
    return 0;
}
