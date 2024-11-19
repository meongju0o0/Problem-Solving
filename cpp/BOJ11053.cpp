#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> items(n); // 수열의 값을 저장할 벡터
    for (int& item : items) {
        cin >> item;
    }

    vector<int> LIS(n, 1); // LIS를 저장할 벡터, 메모 테이블, 모든 원소의 최장증가부분수열의 최소 길이는 1

    for (int i = 0; i < n; i++) {  // i번째 원소에 대해
        for (int j = 0; j < i; j++) { // i보다 앞에 있는 숫자를 탐색
            if (items[i] > items[j]) { // items[i]가 items[j]보다 크다면
                LIS[i] = max(LIS[i], LIS[j] + 1); // i번째 원소의 LIS는 i번째 원소까지의 LIS와 j번째 원소까지의 LIS + 1 중 큰 값
            }
        }
    }

    cout << *ranges::max_element(LIS.begin(), LIS.end()) << "\n";

    return 0;
}