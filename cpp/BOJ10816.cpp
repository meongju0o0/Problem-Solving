#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, int> cards;

    for(int i = 0; i < n; i++) {
        int card;
        cin >> card;
        if(!cards.contains(card)) {
            cards[card] = 1;
        }
        else {
            cards[card]++;
        }
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        int card;
        cin >> card;
        printf("%d ", cards[card]);
    }

    return 0;
}