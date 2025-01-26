#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, ent_x, ent_y;
    cin >> n >> ent_x >> ent_y;

    if (n == 1) {
        cout << "0\n";
    } else if (ent_x == 1 && ent_y == 1) {
        cout << "2\n";
    } else if (ent_x == 1 && ent_y == n) {
        cout << "2\n";
    } else if (ent_x == n && ent_y == 1) {
        cout << "2\n";
    } else if (ent_x == n && ent_y == n) {
        cout << "2\n";
    } else if (ent_x == 1 || ent_y == 1 || ent_x == n || ent_y == n) {
        cout << "3\n";
    } else {
        cout << "4\n";
    }

    return 0;
}