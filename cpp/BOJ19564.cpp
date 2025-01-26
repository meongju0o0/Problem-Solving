#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string given_str;
    cin >> given_str;

    int cnt = 0;
    char prev_str = 0xFF / 2 - 1;
    for (size_t i = 0; i < given_str.size(); i++) {
        if (given_str[i] > prev_str) {
            prev_str = given_str[i];
        } else {
            prev_str = given_str[i];
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}