#include <iostream>
#include <unordered_map>

using namespace std;

long long pow(unordered_map<long long, long long>& memo, const long long a, const long long b, const long long c) {
    if(memo.contains(b)) {
        return memo[b];
    }
    else {
        if(b % 2 == 0) {
            memo[b] = (pow(memo, a, b / 2, c) * pow(memo, a, b / 2, c)) % c;
        }
        else {
            memo[b] = (pow(memo, a, b - 1, c) * a) % c;
        }
        return memo[b];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    cin >> a >> b >> c;

    unordered_map<long long, long long> memo = {
        {0, 1},
        {1, a % c}
    };

    printf("%lld", pow(memo, a, b, c));

    return 0;
}