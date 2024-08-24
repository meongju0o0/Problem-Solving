#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> line(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> line[i];
    }

    sort(line.begin(), line.end());

    vector<int> accumulated_sum(n, 0);

    int sum = 0;
    for(int i = 0; i < n; i++) {
        accumulated_sum[i] = sum + line[i];
        sum += line[i];
    }

    cout << accumulate(accumulated_sum.begin(), accumulated_sum.end(), 0) << endl;
}