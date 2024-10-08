#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> classes(n);
    for(int i = 0; i < n; i++) {
        int start_time, end_time;
        cin >> start_time >> end_time;
        classes[i] = {start_time, end_time};
    }
    ranges::sort(classes.begin(), classes.end());
    /*
     * 후보군: 주어진 수업들
     * 각 후보군을 수업 시작 시간 기준으로 오름차순 정렬
     */

    priority_queue<int, vector<int>, greater<>> pq; // min heap을 활용하여 사용중인 강의실 관리
    /*
     * 후보군의 우선순위: 수업 종료 시간이 작을수록 우선순위가 높다
     * pq.top()은 항상 현재 진행 중인 강의 중 가장 빨리 끝나는 것을 반환한다.
     * 새로 시작하려는 수업은 아래 조건에 따라 강의실의 필요 여부가 나뉜다.
     *
     * 빨리 끝난 수업의 강의실을 다음 수업이 그대로 활용할 수 있으면(직전 종료시간 <= 현재 시작시간): 추가 강의실 불요
     * 빨리 끝난 수업의 강의실을 다음 수업이 활용할 수 없으면(직전 종료시간 > 현재 시작시간): 추가 강의실 필요
     */

    pq.push(classes[0].second); // 첫번째 수업의 종료 시간 삽입
    for(int i = 1; i < n; i++) {
        if (pq.top() <= classes[i].first) { // 현재 수업을 이전과 같은 강의실에서 할 수 있으면(유효성 검사)
            pq.pop(); // 이전 수업은 pq에서 삭제
        }
        pq.push(classes[i].second); // 현재 수업을 pq에 삽입
    }

    printf("%llu", pq.size()); // pq에 남아있는 수업의 수: 최종적으로 필요한 강의실의 개수

    return 0;
}
