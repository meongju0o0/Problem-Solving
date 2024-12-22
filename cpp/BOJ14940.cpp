#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

// 현재 위치(cur_pos)에서 이동 가능한 이웃 좌표를 반환하는 함수
vector<pair<int, int>> get_neighbors(vector<vector<int>>& map, pair<int, int>& cur_pos) {
    vector<pair<int, int>> neighbors(0);

    // 위쪽 이웃 확인
    if (map[cur_pos.first - 1][cur_pos.second] != 0) {
        neighbors.emplace_back(cur_pos.first - 1, cur_pos.second);
    }
    // 아래쪽 이웃 확인
    if (map[cur_pos.first + 1][cur_pos.second] != 0) {
        neighbors.emplace_back(cur_pos.first + 1, cur_pos.second);
    }
    // 왼쪽 이웃 확인
    if (map[cur_pos.first][cur_pos.second - 1] != 0) {
        neighbors.emplace_back(cur_pos.first, cur_pos.second - 1);
    }
    // 오른쪽 이웃 확인
    if (map[cur_pos.first][cur_pos.second + 1] != 0) {
        neighbors.emplace_back(cur_pos.first, cur_pos.second + 1);
    }

    return neighbors; // 이동 가능한 좌표 리스트 반환
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상을 위한 설정
    cin.tie(nullptr); // 입출력 동기화를 해제하여 성능 향상

    int n, m; // 지도 크기 (n: 행, m: 열)
    cin >> n >> m;

    // 지도 입력을 받으며, 가장자리 패딩을 위해 크기 (n+2, m+2)로 설정
    vector<vector<int>> map(n + 2, vector<int>(m + 2, 0));
    pair<int, int> start_point; // 시작 위치 (값이 2인 좌표)

    // 지도 데이터 입력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            // 시작 위치 저장
            if (map[i][j] == 2) {
                start_point = make_pair(i, j);
            }
        }
    }

    // 거리 저장 벡터 및 방문 여부 기록 벡터 초기화
    vector<vector<int>> distances(n + 2, vector<int>(m + 2, 0));
    vector<vector<bool>> visited(n + 2, vector<bool>(m + 2, false));

    queue<pair<int, int>> candidates; // BFS 탐색 대기열
    candidates.push(start_point); // 시작 위치를 대기열에 추가

    int cnt = 0; // 현재 거리 (단계 수)
    while (!candidates.empty()) {
        unsigned candidates_size = candidates.size(); // 현재 단계의 대기열 크기
        for (unsigned i = 0; i < candidates_size; i++) {
            pair<int, int> cur_pos = candidates.front(); // 대기열에서 현재 위치 꺼냄
            candidates.pop();

            // 현재 위치가 방문되지 않았다면 처리
            if (!visited[cur_pos.first][cur_pos.second]) {
                distances[cur_pos.first][cur_pos.second] = cnt; // 거리를 기록
                visited[cur_pos.first][cur_pos.second] = true; // 방문 처리

                // 현재 위치의 이동 가능한 이웃을 탐색
                vector<pair<int, int>> neighbors = get_neighbors(map, cur_pos);
                for (pair<int, int> neighbor : neighbors) {
                    // 방문하지 않은 이웃만 대기열에 추가
                    if (!visited[neighbor.first][neighbor.second]) {
                        candidates.push(neighbor);
                    }
                }
            }
        }
        cnt++; // 다음 단계로 거리 증가
    }

    // 거리 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int distance = distances[i][j]; // 해당 좌표까지의 거리
            bool is_available = (map[i][j] == 1); // 이동 가능한 위치 여부

            // 거리가 0이 아니면 거리 출력
            if (distance != 0) {
                cout << distance << " ";
            }
            // 거리 0이고 이동 가능하면 -1 출력
            else if (is_available) {
                cout << -1 << " ";
            }
            // 이동 불가한 경우 0 출력
            else {
                cout << 0 << " ";
            }
        }
        cout << endl; // 행 구분을 위해 줄바꿈
    }

    return 0;
}
