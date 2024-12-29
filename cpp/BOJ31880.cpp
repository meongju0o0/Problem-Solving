#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    long long max_p = 0;
    for (size_t i = 0; i < n; i++) {
        int add_p;
        cin >> add_p;
        max_p += add_p;
    }
    for (size_t i = 0; i < m; i++) {
        int mul_p;
        cin >> mul_p;
        if (mul_p > 0) {
            max_p *= mul_p;
        }
    }
    printf("%lld", max_p);

    return 0;
}