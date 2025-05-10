#include <iostream>

using namespace std;

int main() {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += i * i;
    }
    std::cout << ans << std::endl;
    return 0;
}