#include <iostream>
#include <vector>

using namespace std;

int factorial(const int n) {
    int result = 1;

    for(int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    cout << factorial(n) << "\n";

    return 0;
}