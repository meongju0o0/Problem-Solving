#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, m;
    cin >> a >> b >> c >> m;

    int work = 0, tired = 0;
    for (int hour = 0; hour < 24; hour++) {
        if (tired + a <= m) {
            work += b;
            tired += a;
        }
        else {
            tired = max(0, tired - c);
        }
    }

    printf("%d", work);

    return 0;
}