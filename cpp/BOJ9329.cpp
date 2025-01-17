#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> prize_infos(n, vector<int>(0));
        vector<int> reward_amount(n);
        vector<int> coach_stickers(m);

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            prize_infos[i].resize(k);
            for (int j = 0; j < k; j++) {
                cin >> prize_infos[i][j];
            }
            cin >> reward_amount[i];
        }

        for (int j = 0; j < m; j++) {
            cin >> coach_stickers[j];
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int min_coach_sticker = INT_MAX;
            for (const int& prize_info : prize_infos[i]) {
                min_coach_sticker = min(min_coach_sticker, coach_stickers[prize_info - 1]);
            }
            sum += min_coach_sticker * reward_amount[i];
        }

        cout << sum << '\n';
    }

    return 0;
}
