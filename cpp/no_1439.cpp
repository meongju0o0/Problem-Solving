#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string binary_digits;
    cin >> binary_digits;

    int cnt_0 = 0;
    int cnt_1 = 0;

    for(int i = 0; i < binary_digits.size(); i++) {
        if(i == 0) {
            if(binary_digits[0] == '0') {
                cnt_0++;
            }
            else if(binary_digits[0] == '1') {
                cnt_1++;
            }
        }
        if(i > 0) {
            if(binary_digits[i-1] == '1' && binary_digits[i] == '0') {
                cnt_0++;
            }
            else if(binary_digits[i-1] == '0' && binary_digits[i] == '1') {
                cnt_1++;
            }
        }
    }

    printf("%d", min(cnt_0, cnt_1));

    return 0;
}