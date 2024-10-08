#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d1, d2;
    cin >> d1 >> d2;

    printf("%.6f", 2 * (d1 + 3.141592 * d2));

    return 0;
}