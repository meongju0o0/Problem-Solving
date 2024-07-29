#include <iostream>
#include <unordered_set>

using namespace std;

long long max_factorial(const long long n, unordered_set<long long>& used_factorial) {
    long long factorial = 1;

    int i = 1;
    while(factorial <= n) {
        factorial *= ++i;
    }
    factorial /= i--;
    while(used_factorial.contains(i) && i > 0) {
        factorial /= i--;
    }
    if(!used_factorial.contains(i)) {
        used_factorial.insert(i);
        return factorial;
    }
    else {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    unordered_set<long long> used_factorial;

    bool is_decomposable = true;
    if(n == 0) {
        is_decomposable = false;
    }
    else {
        while(n > 0) {
            long long myfactorial = max_factorial(n, used_factorial);
            if(myfactorial == -1) {
                is_decomposable = false;
                break;
            }
            n -= myfactorial;
        }
    }

    cout << (is_decomposable ? "YES" : "NO");

    return 0;
}