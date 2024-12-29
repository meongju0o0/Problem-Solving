#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    cin >> n >> h;

    priority_queue<int, vector<int>, greater<>> cards;

    for (int i = 0; i < n; i++) {
        int card;
        cin >> card;
        cards.push(card);
    }

    int cnt = 0;
    while (h > 0) {
        if (cards.empty()) {
            cout << "-1";
            exit(0);
        }

        cnt++;
        h -= cards.top();
        cards.pop();
    }

    cout << cnt;

    return 0;
}