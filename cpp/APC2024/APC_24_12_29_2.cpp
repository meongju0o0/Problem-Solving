#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    queue<int> a;
    for (int i = 0; i < 2 * n; i++) {
        int a_i;
        cin >> a_i;
        a.push(a_i);
    }

    queue<int> b;
    for (int i = 0; i < t; i++) {
        int b_i;
        cin >> b_i;
        b.push(b_i);
    }

    while (!b.empty()) {
        int cur_t = b.front();
        b.pop();

        int cur_a;
        for (int i = 0; i < cur_t; i++) {
            cur_a = a.front();
            if (i != cur_t - 1) {
                a.pop();
                a.push(cur_a);
            }
        }

        printf("%d ", cur_a);
    }

    return 0;
}