#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int get_available_card(vector<int>& cards) {
    for (int j = 8; j >= 0; j--) {
        if (cards[j] > 0) {
            cards[j]--;
            return j + 1;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n = 0;
        vector<int> cards(9);
        for (int& card: cards) {
            cin >> card;
            n += card;
        }

        cards[8] += cards[5];
        cards[5] = 0;

        vector<int> results(n);
        for (int i = 0; i < n; i++) {
            int available_card = get_available_card(cards);

            if (available_card == -1) {
                break;
            }
            else if (i % 2 == 0) {
                results[i / 2] = available_card;
            }
            else if (i % 2 == 1) {
                results[n - 1 - i / 2] = available_card;
            }
        }

        for (const int result: results) {
            cout << result << " ";
        }
        cout << "\n";
    }

    return 0;
}