#include <iostream>
#include <array>
#include <unordered_map>

using namespace std;

array<array<int, 2>, 2> mat_mul(const array<array<int, 2>, 2>& matA, const array<array<int, 2>, 2>& matB) {
    const array<array<int, 2>, 2> result = {
        (matA[0][0] * matB[0][0] + matA[0][1] * matB[1][0]) % 10007,
        (matA[0][0] * matB[0][1] + matA[0][1] * matB[1][1]) % 10007,
        (matA[1][0] * matB[0][0] + matA[1][1] * matB[1][0]) % 10007,
        (matA[1][0] * matB[0][1] + matA[1][1] * matB[1][1]) % 10007
    };

    return result;
}

array<array<int, 2>, 2> mat_pow(unordered_map<int, array<array<int, 2>, 2>*>& memo, const array<array<int, 2>, 2>& matA, const int pow) {
    if(memo.contains(pow)) {
        return *memo[pow];
    }
    else {
        if(pow % 2 == 0) {
            array<array<int, 2>, 2> result = mat_mul(mat_pow(memo, matA, pow / 2), mat_pow(memo, matA, pow / 2));
            memo[pow] = &result;
            return *memo[pow];
        }
        else {
            array<array<int, 2>, 2> result = mat_mul(mat_pow(memo, matA, pow - 1), matA);
            memo[pow] = &result;
            return *memo[pow];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    array<array<int, 2>, 2> matA = {
        1, 2,
        1, 0
    };
    unordered_map<int, array<array<int, 2>, 2>*> memo;
    memo[1] = &matA;

    printf("%d", mat_pow(memo, matA, n)[0][0]);

    return 0;
}