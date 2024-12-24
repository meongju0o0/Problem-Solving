#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sum = 0;
    int max = -1;
    for (int i = 0; i < n; i++) {
        int item;
        cin >> item;
        if (item > max) {
            max = item;
        }
        sum += item;
    }

    printf("%d", sum - max);

    return 0;
}