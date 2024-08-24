#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string input;
    cin >> input;

    int temp_cnt = 0, cnt = 0;
    for(int i = 0; i < m - 1; i++) {
        if(input.substr(i, 3) == "IOI") {
            i++;
            temp_cnt += 1;
            if(temp_cnt == n) {
                cnt++;
                temp_cnt--;
            }
        }
        else {
            temp_cnt = 0;
        }
    }
    printf("%d", cnt);

    return 0;
}