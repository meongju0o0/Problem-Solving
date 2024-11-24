﻿#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1, str2;
    cin >> str1 >> str2;

    const size_t str1_len = str1.size();
    const size_t str2_len = str2.size();

    vector<vector<int>> memo(str1_len + 1, vector<int>(str2_len + 1, 0));

    for(size_t i = 1; i <= str1_len; i++) {
        for(size_t j = 1; j <= str2_len; j++) {
            if(str1[i - 1] == str2[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1] + 1;
            }
            else {
                memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
            }
        }
    }

    printf("%d", memo[str1_len][str2_len]);

    return 0;
}