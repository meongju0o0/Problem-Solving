#include <iostream>
#include <vector>

using namespace std;

bool is_promising(vector<vector<bool>>& memo, const int n, const int cur_row, const int cur_col) {
    for (int i = cur_row - 1; i >= 0; i--) {
        if (memo[i][cur_col]) {
            return false;
        }
    }

    for (int i = cur_row - 1, j = cur_col - 1; i >= 0 && j >= 0; i--, j--) {
        if (memo[i][j]) {
            return false;
        }
    }

    for (int i = cur_row - 1, j = cur_col + 1; i >= 0 && j < n; i--, j++) {
        if (memo[i][j]) {
            return false;
        }
    }

    return true;
}

void n_queens(vector<vector<bool>>& memo, int& cnt, const int cur_row, const int n) {
    if (cur_row == n) {
        cnt++;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (is_promising(memo, n, cur_row, i)) {
                memo[cur_row][i] = true;
                n_queens(memo, cnt, cur_row + 1, n);
                memo[cur_row][i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<bool>> memo(n, vector<bool>(n, false));
    int cnt = 0;

    n_queens(memo, cnt, 0, n);
    cout << cnt << "\n";

    return 0;
}