#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> accumulated_sum(n);

    for(int i = 0; i < n; i++) {
        int item;
        cin >> item;
        if(i != 0) {
            accumulated_sum[i] = accumulated_sum[i - 1] + item;
        }
        else {
            accumulated_sum[i] = item;
        }
    }

    vector<int> partial_sums(n - k + 1);
    int max = INT_MIN;
    for(int i = 0; i < n - k + 1; i++) {
        int temp_sum;
        if(i != 0) {
            temp_sum = accumulated_sum[i+k-1] - accumulated_sum[i - 1];
        }
        else {
            temp_sum = accumulated_sum[i+k-1];
        }
        if(temp_sum > max) {
            max = temp_sum;
        }
    }

    printf("%d", max);

    return 0;
}