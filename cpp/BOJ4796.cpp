#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int cnt = 1; ; cnt++) {
        int l, p, v;
        cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0) {
            break;
        }

        int days = 0;
        while (v > 0) {
            if (v > l) {
                days += l;
                v -= p;
            }
            else {
                days += v;
                v = 0;
            }
        }

        printf("Case %d: %d\n", cnt, days);
    }

    return 0;
}