#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> ramens(n + 2, 0);
    for (int i = 0; i < n; i++) {
        cin >> ramens[i];
    }

    int cost = 0;

    for (int i = 0; i < n; i++) {
        if (ramens[i + 1] > ramens[i + 2]) {
            const int two_bowl = min(ramens[i], ramens[i + 1] - ramens[i + 2]);
            ramens[i] -= two_bowl;
            ramens[i + 1] -= two_bowl;
            cost += two_bowl * 5;
        }

        const int three_bowl = min({ramens[i], ramens[i + 1], ramens[i + 2]});
        ramens[i] -= three_bowl;
        ramens[i + 1] -= three_bowl;
        ramens[i + 2] -= three_bowl;
        cost += three_bowl * 7;

        const int two_bowl = min(ramens[i], ramens[i + 1]);
        ramens[i] -= two_bowl;
        ramens[i + 1] -= two_bowl;
        cost += two_bowl * 5;

        cost += ramens[i] * 3;
        ramens[i] = 0;
    }

    printf("%d", cost);

    return 0;
}
