#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, l ,k;
    cin >> n >> l >> k;
    
    vector<pair<int, int>> problems(n);
    for (pair<int, int>& problem: problems) {
        cin >> problem.first >> problem.second;
    }

    ranges::sort(problems.begin(), problems.end(), cmp);

    int total_score = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cnt >= k) break;

        if (problems[i].second <= l) {
            cnt++;
            total_score += 140;
        } else if (problems[i].first <= l) {
            cnt++;
            total_score += 100;
        }
    }

    cout << total_score << endl;

    return 0;
}