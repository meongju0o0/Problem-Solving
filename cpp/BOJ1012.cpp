#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

// 맵에서 시작 위치를 찾아 반환하는 함수
// map: 2D 배열, n: 맵의 행 크기, m: 맵의 열 크기
tuple<int, int> get_start_pos(const vector<vector<int>>& map, const int n, const int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j]) { // 값이 1인 첫 번째 좌표를 찾으면 반환
                return make_tuple(i, j);
            }
        }
    }
    return make_tuple(-1, -1); // 값이 1인 좌표가 없다면 (-1, -1) 반환
}

// 연결 요소(그래프)의 개수를 계산하는 함수
int num_graphs(vector<vector<int>>& map, const int n, const int m) {
    int num_graphs = 0; // 연결 요소 개수
    queue<tuple<int, int>> candidates; // BFS 탐색을 위한 큐

    while (true) {
        // 시작 위치를 찾음
        tuple<int, int> start_pos = get_start_pos(map, n, m);
        if (start_pos == make_tuple(-1, -1)) { // 더 이상 시작 위치가 없으면 종료
            break;
        } else {
            num_graphs++; // 새로운 연결 요소 발견, 개수 증가
            candidates.push(start_pos); // BFS 탐색 시작

            while (!candidates.empty()) {
                tuple<int, int> cur_pos = candidates.front(); // 현재 탐색 위치
                candidates.pop();

                const int y_pos = get<0>(cur_pos); // 현재 위치의 y 좌표
                const int x_pos = get<1>(cur_pos); // 현재 위치의 x 좌표

                if (map[y_pos][x_pos]) { // 방문하지 않은 노드라면
                    map[y_pos][x_pos] = 0; // 방문 처리 (0으로 변경)

                    // 상하좌우 인접한 노드가 1이면 큐에 추가
                    if (map[y_pos - 1][x_pos]) {
                        candidates.emplace(y_pos - 1, x_pos);
                    }
                    if (map[y_pos + 1][x_pos]) {
                        candidates.emplace(y_pos + 1, x_pos);
                    }
                    if (map[y_pos][x_pos - 1]) {
                        candidates.emplace(y_pos, x_pos - 1);
                    }
                    if (map[y_pos][x_pos + 1]) {
                        candidates.emplace(y_pos, x_pos + 1);
                    }
                }
            }
        }
    }

    return num_graphs; // 연결 요소의 총 개수 반환
}

int main() {
    ios::sync_with_stdio(false); // 입출력 성능 향상
    cin.tie(nullptr); // 입출력 동기화 비활성화

    int t; // 테스트 케이스 수
    cin >> t;

    while (t--) {
        int m, n, k; // m: 맵의 열 크기, n: 행 크기, k: 배추의 위치 개수
        cin >> m >> n >> k;

        // 2D 맵 생성, 외곽을 0으로 초기화
        vector<vector<int>> map(n + 2, vector<int>(m + 2, 0));

        // 배추의 위치 입력
        while (k--) {
            int x, y;
            cin >> x >> y;
            map[y + 1][x + 1] = 1; // 입력된 위치에 1 표시 (1 기반 좌표)
        }

        // 연결 요소의 개수 출력
        printf("%d\n", num_graphs(map, n, m));
    }

    return 0;
}
