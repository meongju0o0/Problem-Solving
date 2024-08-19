#include <iostream>
#include <array>
#include <unordered_map>

using namespace std;

array<array<unsigned long long, 2>, 2> mat_mul(const array<array<unsigned long long, 2>, 2>& matA, const array<array<unsigned long long, 2>, 2>& matB) {
    const array<array<unsigned long long, 2>, 2> result = {
        (matA[0][0] * matB[0][0] + matA[0][1] * matB[1][0]) % 1000000007,
        (matA[0][0] * matB[0][1] + matA[0][1] * matB[1][1]) % 1000000007,
        (matA[1][0] * matB[0][0] + matA[1][1] * matB[1][0]) % 1000000007,
        (matA[1][0] * matB[0][1] + matA[1][1] * matB[1][1]) % 1000000007
    };

    return result;
}

array<array<unsigned long long, 2>, 2> mat_pow(unordered_map<unsigned long long, array<array<unsigned long long, 2>, 2>*>& memo, const array<array<unsigned long long, 2>, 2>& matA, const unsigned long long& pow) {
    if(memo.contains(pow)) {
        return *(memo[pow]);
    }
    else if(pow%2 == 0) {
        array<array<unsigned long long, 2>, 2> result = mat_mul(mat_pow(memo, matA, pow/2), mat_pow(memo, matA, pow/2));
        memo[pow] = &result;
        return *(memo[pow]);
    }
    else {
        array<array<unsigned long long, 2>, 2> result = mat_mul(mat_mul(mat_pow(memo, matA, pow/2), mat_pow(memo, matA, pow/2)), matA);
        memo[pow] = &result;
        return *(memo[pow]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n;
    cin >> n;

    array<array<unsigned long long, 2>, 2> matA = {
        1, 1,
        1, 0
    };
    unordered_map<unsigned long long, array<array<unsigned long long, 2>, 2>*> memo;
    memo[1] = &matA;

    if(n == 0 || n == 1) {
        printf("%llu", n);
    }
    else {
        array<array<unsigned long long, 2>, 2> result = mat_pow(memo, matA, n-1);
        printf("%llu ", result[0][0]);
    }

    return 0;
}