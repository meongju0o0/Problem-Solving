#include <iostream>
#include <vector>
#include <set>

using namespace std;

void make_series(const vector<int>& numbers, const int& n, const vector<int>& series, set<vector<int>>& memo) {
    if(n == 0) {
        memo.insert(series);
    }
    else {
        for(const int& number: numbers) {
            if(n >= number) {
                vector<int> temp_series = series;
                temp_series.push_back(number);
                make_series(numbers, n-number, temp_series, memo);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<int> numbers = {1, 2, 3};

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> series(0);
        set<vector<int>> memo;

        make_series(numbers, n, series, memo);

        printf("%llu\n", memo.size());
    }

    return 0;
}