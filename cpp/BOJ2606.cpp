#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

// 그래프 클래스 정의
class Graph {
private:
    vector<vector<int>> edges; // 그래프의 인접 리스트를 저장하는 벡터
public:
    Graph() = default; // 기본 생성자

    // 인접 리스트를 초기화하는 생성자
    explicit Graph(const vector<vector<int>>& _edges) {
        edges = _edges;
    }

    // 주어진 정점의 이웃 정점을 반환하는 함수
    [[nodiscard]] vector<int> get_neighbors(const int& vertex) {
        return edges[vertex];
    }
};

// 감염된 컴퓨터의 수를 계산하는 함수
int num_infected_computer(Graph& graph) {
    unordered_set<int> visited; // 방문한 정점을 저장하는 집합
    queue<int> candidates; // 탐색 대기열
    candidates.push(0); // 초기 컴퓨터(정점 0)를 대기열에 추가

    while (!candidates.empty()) {
        int cur_vertex = candidates.front(); // 대기열에서 정점을 꺼냄
        candidates.pop();

        if (!visited.contains(cur_vertex)) { // 해당 정점을 아직 방문하지 않았다면
            visited.insert(cur_vertex); // 정점을 방문 처리
            // 현재 정점의 이웃들을 확인하여 방문하지 않은 정점을 대기열에 추가
            for (const int& neighbor: graph.get_neighbors(cur_vertex)) {
                if (!visited.contains(neighbor)) {
                    candidates.push(neighbor);
                }
            }
        }
    }

    // 방문한 정점의 수에서 초기 컴퓨터(0번)를 제외한 수를 반환
    return static_cast<int>(visited.size()) - 1;
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상을 위해 동기화를 해제
    cin.tie(nullptr); // cin과 cout의 묶음을 해제하여 입출력 성능 최적화

    int num_vertices, num_edges; // 정점 수와 간선 수를 저장
    cin >> num_vertices >> num_edges;

    // 각 정점의 연결 정보를 저장할 벡터 초기화
    vector<vector<int>> edges(num_vertices);

    // 간선 정보 입력
    for (int i = 0; i < num_edges; i++) {
        int u, v; // 연결된 두 정점을 입력받음
        cin >> u >> v;
        edges[u - 1].push_back(v - 1); // 0-based 인덱스로 변환하여 저장
        edges[v - 1].push_back(u - 1); // 무방향 그래프이므로 양쪽 연결
    }

    // 그래프 생성
    Graph graph = Graph(edges);

    // 감염된 컴퓨터 수 계산 및 출력
    printf("%d", num_infected_computer(graph));

    return 0;
}
