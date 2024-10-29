#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    priority_queue<int, vector<int>, greater<>> cards;

    cin >> n;
    while(n--) {
        int num_cards;
        cin >> num_cards;
        cards.push(num_cards);
    }

    int merge_cnt = 0;
    while(cards.size() != 1) {
        const int card1 = cards.top();
        cards.pop();
        const int card2 = cards.top();
        cards.pop();
        merge_cnt += (card1 + card2);
        cards.push(card1 + card2);
    }

    printf("%d", merge_cnt);

    return 0;
}