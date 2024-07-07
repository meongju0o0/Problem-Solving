#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int n, k;
    cin >> n >> k;

    set<int> coin_values;
    int temp_value;
    for(int i = 0; i < n; i++) {
        cin >> temp_value;
        coin_values.insert(-temp_value);
    }

    int cnt = 0;
    while(k != 0) {
        cnt++;
        for(const int& coin_value: coin_values) {
            if (k + coin_value >= 0) {
                k += coin_value;
                break;
            }
        }
    }

    cout << cnt;
    return 0;
}