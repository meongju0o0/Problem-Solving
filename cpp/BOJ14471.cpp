#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> cards(m);

    for (int i = 0; i < m; i++) {
        cin >> cards[i].first >> cards[i].second;
    }

    ranges::sort(cards.begin(), cards.end(),
        [] (const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; });

    int cnt = 0;
    for (int i = 0; i < m - 1; i++) {
        if (cards[i].first < n) {
            cnt += n - cards[i].first;
        }
    }

    printf("%d", cnt);

    return 0;
}