#include <iostream>

using namespace std;

void z_ordering(const int n, const int r, const int c, const int y, const int x, int& cnt) {
    if(n == 2) {
        for(int i = y; i < y + n; i++) {
            for(int j = x; j < x + n; j++) {
                if(i == r && j == c) {
                    printf("%d", cnt);
                }
                cnt++;
            }
        }
    }
    else {
        const int n_div_2 = n >> 1;
        if(r < y + n_div_2 && c < x + n_div_2) {
            z_ordering(n_div_2, r, c, y, x, cnt);
        }
        else if(r < y + n_div_2 && c >= x + n_div_2) {
            cnt += n_div_2 * n_div_2;
            z_ordering(n_div_2, r, c, y, x + n_div_2, cnt);
        }
        else if(r >= y + n_div_2 && c < x + n_div_2) {
            cnt += 2 * n_div_2 * n_div_2;
            z_ordering(n_div_2, r, c, y + n_div_2, x, cnt);
        }
        else if(r >= y + n_div_2 && c >= x + n_div_2) {
            cnt += 3 * n_div_2 * n_div_2;
            z_ordering(n_div_2, r, c, y + n_div_2, x + n_div_2, cnt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, c;
    cin >> n >> r >> c;
    int cnt = 0;
    z_ordering(1 << n, r, c, 0, 0, cnt);

    return 0;
}