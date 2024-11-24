#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// (1,1)에서 (n,m)까지의 최단 경로 길이를 계산하는 함수
int get_path_cnt(vector<vector<int>>& map, const int n, const int m) {
    queue<tuple<int, int>> candidates; // BFS 탐색을 위한 큐
    unordered_map<string, int> path_cnts; // 각 좌표까지의 경로 길이를 저장하는 해시맵

    // 시작 지점 초기화
    candidates.emplace(1, 1); // 시작 위치를 큐에 삽입
    path_cnts["1,1"] = 1; // 시작 지점의 경로 길이는 1

    // BFS 탐색 시작
    while (!candidates.empty()) {
        tuple<int, int> cur_pos = candidates.front(); // 현재 탐색 위치
        candidates.pop();

        const int y_pos = get<0>(cur_pos); // 현재 위치의 y 좌표
        const int x_pos = get<1>(cur_pos); // 현재 위치의 x 좌표
        const int cur_path_cnt = path_cnts[to_string(y_pos) + "," + to_string(x_pos)]; // 현재 위치까지의 경로 길이

        if (map[y_pos][x_pos]) { // 현재 위치가 이동 가능한 경우
            map[y_pos][x_pos] = 0; // 방문 처리 (0으로 변경)

            // 상하좌우 인접한 위치 탐색
            if (map[y_pos + 1][x_pos]) { // 아래쪽
                candidates.emplace(y_pos + 1, x_pos); // 큐에 삽입
                path_cnts[to_string(y_pos + 1) + "," + to_string(x_pos)] = cur_path_cnt + 1; // 경로 길이 갱신
            }
            if (map[y_pos - 1][x_pos]) { // 위쪽
                candidates.emplace(y_pos - 1, x_pos);
                path_cnts[to_string(y_pos - 1) + "," + to_string(x_pos)] = cur_path_cnt + 1;
            }
            if (map[y_pos][x_pos - 1]) { // 왼쪽
                candidates.emplace(y_pos, x_pos - 1);
                path_cnts[to_string(y_pos) + "," + to_string(x_pos - 1)] = cur_path_cnt + 1;
            }
            if (map[y_pos][x_pos + 1]) { // 오른쪽
                candidates.emplace(y_pos, x_pos + 1);
                path_cnts[to_string(y_pos) + "," + to_string(x_pos + 1)] = cur_path_cnt + 1;
            }
        }
    }

    // (n, m) 좌표까지의 경로 길이를 반환
    return path_cnts[to_string(n) + "," + to_string(m)];
}

int main() {
    ios::sync_with_stdio(false); // 입출력 성능 향상
    cin.tie(nullptr); // 입출력 동기화 비활성화

    int n, m; // n: 맵의 행 크기, m: 맵의 열 크기
    cin >> n >> m;

    // 2D 맵 생성, 외곽을 0으로 초기화
    vector<vector<int>> map(n + 2, vector<int>(m + 2, 0));

    // 맵 입력 받기
    for (int i = 1; i <= n; i++) {
        string line;
        cin >> line; // 한 줄씩 입력받기
        for (int j = 1; j <= m; j++) {
            map[i][j] = line.front() - '0'; // 문자 '0' 또는 '1'을 숫자로 변환
            line.erase(line.begin()); // 처리한 문자를 제거
        }
    }

    // 최단 경로 길이 출력
    printf("%d\n", get_path_cnt(map, n, m));

    return 0;
}
