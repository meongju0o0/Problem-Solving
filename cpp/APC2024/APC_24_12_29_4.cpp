#include <iostream>

using namespace std;

#define MOD 1000000007

long long pow(const long long x, const long long p) {
    if (p == 0) {
        return 1;
    }
    else if (p == 1) {
        return x % MOD;
    }
    else {
        const long long half = pow(x, p / 2) % MOD;
        if (p % 2 == 0) {
            return (half * half) % MOD;
        } else {
            return (half * half % MOD) * x % MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        long long n;
        cin >> n;

        if (n == 1) {
            printf("5\n");
        }
        else {
            const long long total = pow(5, n) % MOD;
            const long long exclude = pow(5, n - 1) % MOD;
            const long long result = (total - exclude + MOD) % MOD;
            printf("%lld\n", result);
        }
    }

    return 0;
}
