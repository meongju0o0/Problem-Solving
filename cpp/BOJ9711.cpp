#include <iostream>
#include <array>
#include <unordered_map>

typedef unsigned long long dtype;

using namespace std;

array<array<dtype, 2>, 2> mat_mul(const array<array<dtype, 2>, 2>& matA, const array<array<dtype, 2>, 2>& matB, const dtype mod) {
    array<array<dtype, 2>, 2> result = matA;

    result[0][0] = (matA[0][0] * matB[0][0] + matA[0][1] * matB[1][0]) % mod;
    result[0][1] = (matA[0][0] * matB[1][0] + matA[0][1] * matB[1][1]) % mod;
    result[1][0] = (matA[1][0] * matB[0][0] + matA[1][1] * matB[1][0]) % mod;
    result[1][1] = (matA[1][0] * matB[0][1] + matA[1][1] * matB[1][1]) % mod;

    return result;
}

array<array<dtype, 2>, 2> mat_pow(unordered_map<dtype, array<array<dtype, 2>, 2>*>& memo, const array<array<dtype, 2>, 2>& matA, const dtype& pow, const dtype mod) {
    if(memo.contains(pow)) {
        return *memo[pow];
    }
    else if(pow%2 == 0) {
        array<array<dtype, 2>, 2> result = mat_mul(mat_pow(memo, matA, pow/2, mod), mat_pow(memo, matA, pow/2, mod), mod);
        memo[pow] = &result;
        return *memo[pow];
    }
    else {
        array<array<dtype, 2>, 2> result = mat_mul(mat_mul(mat_pow(memo, matA, pow/2, mod), mat_pow(memo, matA, pow/2, mod), mod), matA, mod);
        memo[pow] = &result;
        return *memo[pow];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dtype cases;
    cin >> cases;

    for(int i = 1; i <= cases; i++) {
        dtype p, q;
        cin >> p >> q;
        array<array<dtype, 2>, 2> matA = {
            1, 1,
            1, 0
        };
        unordered_map<dtype, array<array<dtype, 2>, 2>*> memo;
        memo[1] = &matA;

        if(p == 0 || p == 1) {
            printf("Case #%d: %lld\n", i, p % q);
        }
        else {
            array<array<dtype, 2>, 2> result = mat_pow(memo, matA, p-1, q);
            printf("Case #%d: %lld\n", i, result[0][0] % q);
        }
    }

    return 0;
}