#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int cur_milk = 0;
    int drunk_milks = 0;
    for (int i = 0; i < n; i++) {
        int milk_input;
        cin >> milk_input;

        if (milk_input == cur_milk) {
            drunk_milks++;
            cur_milk = (cur_milk + 1) % 3;
        }
    }

    printf("%d", drunk_milks);

    return 0;
}