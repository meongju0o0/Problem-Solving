#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double w, h;
    cin >> w >> h;

    printf("%.1f", 0.5 * w * h);
}