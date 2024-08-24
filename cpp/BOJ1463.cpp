#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void make_1(int n, int cnt, vector<int>& memo) {
    if(n == 1) {
        if(memo[n] >= cnt) {
            memo[1] = cnt;
        }
    }
    else {
        if(n % 3 == 0) {
            if(memo[n] >= cnt) {
                memo[n] = cnt;
                make_1(n/3, cnt+1, memo);
            }
        }
        if(n % 2 == 0) {
            if(memo[n] >= cnt) {
                memo[n] = cnt;
                make_1(n/2, cnt+1, memo);
            }
        }
        if(memo[n] >= cnt) {
            memo[n] = cnt;
            make_1(n-1, cnt+1, memo);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> memo(n+1, INT_MAX);

    make_1(n, 0, memo);

    cout << memo[1] << endl;

    return 0;
}