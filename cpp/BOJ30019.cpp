#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> reservations(n, 0);

    for (int i = 0; i < m; i++) {
        int k, s, e;
        cin >> k >> s >> e;

        if (reservations[k - 1] <= s) {
            reservations[k - 1] = e;
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}