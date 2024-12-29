#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const string target_str = "KOREA";
    string given_str;
    cin >> given_str;

    int cnt = 0;
    for (const char& ch: given_str) {
        if (target_str[cnt % 5] == ch) {
            ++cnt;
        }
    }

    printf("%d", cnt);

    return 0;
}