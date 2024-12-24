#include <iostream>

using namespace std;

constexpr int coin_set[4] = {25, 10, 5, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int rest;
        cin >> rest;

        const int quarter = rest / coin_set[0];
        const int dime = (rest - coin_set[0] * quarter) / coin_set[1];
        const int nickel = (rest - (coin_set[0] * quarter + coin_set[1] * dime)) / coin_set[2];
        const int penny = (rest - (coin_set[0] * quarter + coin_set[1] * dime + coin_set[2] * nickel)) / coin_set[3];

        printf("%d %d %d %d\n", quarter, dime, nickel, penny);
    }

    return 0;
}