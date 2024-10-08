#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int cnt = 0;
    while(n > 0) {
        if(n >= 10 && n % 2 == 0) {
            // 후보군1-1(최상의 경우, 5원짜리 사용)
            // 현재 n이 짝수인 경우, 그대로 짝수인 상태를 유지해야 2원짜리 잔돈을 사용할 수 있음.
            // 5원짜리 2개를 사용하는 경우를 구현
            n -= 10;
            cnt += 2;
        }
        else if(n >= 5 && n % 2 == 1) {
            // 후보군1-2(최상의 경우, 5원짜리 사용)
            // 현재 n이 홀수인 경우, n을 짝수로 만들어줘야 2원짜리 잔돈을 사용할 수 있음.
            // 5원짜리 1개를 사용하는 경우를 구현
            n -= 5;
            cnt++;
        }
        else {
            // 후보군3(차상의 경우, 2원짜리 사용)
            // n이 2 이상이 아닌 경우(n이 1인 경우)에도 작업을 수행하여 n을 음수로 만듦
            // -> 잔돈을 거슬러 줄 수 없는 경우를 판단
            n -= 2;
            cnt++;
        }
    }

    if(n == 0) {
        printf("%d", cnt);
    }
    else {
        printf("-1");
    }

    return 0;
}