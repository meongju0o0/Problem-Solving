#include <iostream>
#include <unordered_map>
#include <cmath>

#define MOD 1000000000

typedef long long dtype;
typedef int keytype;

using namespace std;

dtype fibo(unordered_map<keytype, dtype>& memo, const keytype n) {
    if(memo.contains(n)) {
        return memo[n];
    }
    else {
        if(n > 1) {
            memo[n] = (fibo(memo, n - 1) + fibo(memo, n - 2)) % MOD;
            return memo[n];
        }
        else {
            memo[n] = (fibo(memo, n + 2) - fibo(memo, n + 1)) % MOD;
            return memo[n];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    keytype n;
    cin >> n;

    unordered_map<keytype, dtype> memo = {{0, 0}, {1, 1}};
    const dtype result = fibo(memo, n);
    if(result > 0) {
        printf("%d\n", 1);
    }
    else if(result == 0) {
        printf("%d\n", 0);
    }
    else {
        printf("%d\n", -1);
    }
    printf("%lld\n", abs(result));

    return 0;
}