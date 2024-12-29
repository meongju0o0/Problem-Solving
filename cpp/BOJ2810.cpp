#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string str;
    cin >> str;

    int cnt_s = 0, cnt_l = 0;
    for (const char& ch: str) {
        if (ch == 'S') {
            cnt_s++;
        }
        else if (ch == 'L') {
            cnt_l++;
        }
    }
    cnt_l /= 2;

    printf("%d", min(n, n + 1 - cnt_l));

    return 0;
}