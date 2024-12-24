#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        printf("%d ", i % 2 + 1);
    }
    printf("%d", n % 2 ? 3 : 2);

    return 0;
}