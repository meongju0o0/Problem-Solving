#include <iostream>
#include <string>

using namespace std;

/*
 * 문제에서 주어진 상황은 a -> b로 바꿔야 하는 상황이 주어짐
 * 순차적으로 진행하는 경우 그리디로 해결할 수 없음
 * 2를 곱하는 것이 b에 도달할 수 있는 것인지, 1을 추가하는 것이 b에 도달할 수 있는 것인지 판별하기 힘듦
 * 또한, b에 도달하는 방법의 가지수가 여러가지로 될 수 있고, 이 중에서 최적해를 구하려면 너비우선탐색을 적용하는것이 맞음
 *
 *
 * 한편, 이미 주어진 b에서 a로 도달하는 방법도 생각해 볼 수 있음
 * 이때, 가능한 후보군은 (맨 오른쪽 1을 빼기, 2로 나누기)
 *
 * 현재 b가 1로 끝나는 경우는 홀수이므로 2로 나누는 선택을 할 수 없음
 * 다른 선택지 없이 b의 맨 오른쪽에서 1을 빼면 됨
 *
 * 현재 b가 짝수이면서 b의 맨 오른쪽이 1일 수도 없음
 * 다른 선택지 없이 b를 2로 나누면 됨
 *
 * 따라서, 선택지의 우선순위는 고려하지 않아도 된다
 *
 * 한편, 이와 비슷한 문제로는 'BOJ12904 A와 B'가 있다.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    int cnt = 1;
    while(a < b) {
        string temp_str = to_string(b);
        if(temp_str.back() == '1') {
            // 맨 오른쪽 1을 빼는 후보군, Case1
            temp_str.pop_back();
            b = stoi(temp_str);
        }
        else if(b % 2 == 0) {
            // 2로 나누는 후보군, Case2
            b /= 2;
        }
        else {
            // a로 도달이 불가능한 경우, Case3
            break;
        }
        cnt++;
    }

    if(a == b) {
        printf("%d", cnt);
    }
    else { // a에 도달하지 못했거나(Case3) b가 a보다 더 작아져버린 경우(Case1, 2)
        printf("-1");
    }

    return 0;
}