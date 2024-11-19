#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> scores(n); // 각 계단의 점수를 저장
    for (int &score : scores) {
        cin >> score;
    }

    vector<int> accumulated_scores(n); // 각 계단까지의 최대 점수를 저장할 메모 테이블
    if (n >= 1) { // n이 1 이상인 경우, 첫 번째 계단 점수 초기화
        accumulated_scores[0] = scores[0];
    }
    if (n >= 2) { // n이 2 이상인 경우, 두 번째 계단 점수 초기화
        accumulated_scores[1] = scores[0] + scores[1];
    }
    if (n >= 3) { // n이 3 이상인 경우, 세 번째 계단 점수 초기화
        accumulated_scores[2] = max(scores[0] + scores[2], scores[1] + scores[2]);
    }

    // 4번째 부터 아래 점화식을 통해 최대 점수 계산 및 저장
    for (int i = 3; i < n; i++) {
        // 점화식: 두 가지 경우 중 최대값 선택
        // 1. (i-2) 계단까지의 최대 점수 + 현재 계단 점수
        // 2. (i-3) 계단까지의 최대 점수 + 이전 계단 점수 + 현재 계단 점수
        accumulated_scores[i] = max(accumulated_scores[i - 2] + scores[i],
                                    accumulated_scores[i - 3] + scores[i - 1] + scores[i]);
    }

    cout << accumulated_scores[n - 1] << endl;

    return 0;
}
