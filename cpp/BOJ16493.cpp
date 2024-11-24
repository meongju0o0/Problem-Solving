#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define KEY_MUL 100

using namespace std;

inline int make_key(const int num_days, const int num_chapters) {
    return num_days * KEY_MUL + num_chapters;
}

int page_sack(unordered_map<int, int>& memo, const vector<pair<int, int>>& chapters, const int n, const int m) {
    const int key = make_key(n, m);
    if(memo.contains(key)) {
        return memo[key];
    }
    else if(n == 0 || m == 0) {
        return 0;
    }
    else {
        const int cur_days = chapters[m - 1].first;
        const int cur_pages = chapters[m - 1].second;

        if(cur_days <= n) {
            memo[key] = max(page_sack(memo, chapters, n, m - 1), cur_pages + page_sack(memo, chapters, n - cur_days, m - 1));
            return memo[key];
        }
        else {
            return page_sack(memo, chapters, n, m - 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_days, num_chapters;
    cin >> num_days >> num_chapters;

    vector<pair<int, int>> chapters(num_chapters);

    for(pair<int, int>& chapter: chapters) {
        cin >> chapter.first >> chapter.second;
    }

    unordered_map<int, int> memo;

    printf("%d", page_sack(memo, chapters, num_days, num_chapters));

    return 0;
}