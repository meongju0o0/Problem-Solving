#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// 그래프 클래스 정의
class Graph {
private:
    vector<int> nodes; // 그래프의 노드 저장
    vector<pair<int, int>> edges; // 그래프의 간선 저장
public:
    Graph() = default; // 기본 생성자

    // 노드를 그래프에 추가
    void add_node(int node) {
        nodes.push_back(node);
    }

    // 간선을 그래프에 추가
    void add_edge(pair<int, int> edge) {
        edges.push_back(edge);
    }

    // 노드 목록 반환 (정렬된 상태로 반환)
    vector<int> get_nodes() {
        sort(nodes.begin(), nodes.end());
        return nodes;
    }

    // 간선 목록 반환
    vector<pair<int, int>> get_edges() {
        return edges;
    }

    // 그래프에 포함된 노드 개수 반환
    int num_nodes() {
        return nodes.size();
    }

    // 그래프에 포함된 간선 개수 반환
    int num_edges() {
        return edges.size();
    }

    // 특정 노드의 이웃 노드 목록 반환 (정렬된 상태로 반환)
    vector<int> get_neighbors(int node) {
        vector<int> neighbors;
        for (pair<int, int>& edge : edges) {
            if (edge.first == node) {
                neighbors.push_back(edge.second);
            } else if (edge.second == node) {
                neighbors.push_back(edge.first);
            }
        }
        sort(neighbors.begin(), neighbors.end());
        return neighbors;
    }
};

// DFS(깊이 우선 탐색) 클래스 정의
class DFS {
private:
    Graph graph; // 탐색에 사용할 그래프
    stack<int> trace_stack; // 탐색 경로를 추적할 스택
    vector<int> DFS_path; // DFS 결과 경로
    unordered_set<int> visited; // 방문한 노드 집합
public:
    DFS(Graph& graph) : graph(graph) {} // 생성자

    // 시작 노드부터 DFS 경로를 반환
    vector<int> get_DFS_path(int enter_vertex) {
        trace_stack.push(enter_vertex); // 시작 노드를 스택에 추가

        while (!trace_stack.empty()) {
            int vertex = trace_stack.top(); // 스택의 맨 위 노드 가져오기
            trace_stack.pop(); // 스택에서 제거

            if (visited.find(vertex) == visited.end()) { // 방문하지 않은 노드라면
                visited.insert(vertex); // 방문 표시
                DFS_path.push_back(vertex); // 경로에 추가

                // 현재 노드의 이웃 노드를 스택에 추가 (역순으로 추가)
                vector<int> neighbors = graph.get_neighbors(vertex);
                for (int i = neighbors.size() - 1; i >= 0; i--) {
                    if (visited.find(neighbors[i]) == visited.end()) {
                        trace_stack.push(neighbors[i]);
                    }
                }
            }
        }
        return DFS_path;
    }
};

// BFS(너비 우선 탐색) 클래스 정의
class BFS {
private:
    Graph graph; // 탐색에 사용할 그래프
    queue<int> trace_queue; // 탐색 경로를 추적할 큐
    vector<int> BFS_path; // BFS 결과 경로
    unordered_set<int> visited; // 방문한 노드 집합
public:
    BFS(Graph& graph) : graph(graph) {} // 생성자

    // 시작 노드부터 BFS 경로를 반환
    vector<int> get_BFS_path(int enter_vertex) {
        trace_queue.push(enter_vertex); // 시작 노드를 큐에 추가

        while (!trace_queue.empty()) {
            int vertex = trace_queue.front(); // 큐의 맨 앞 노드 가져오기
            trace_queue.pop(); // 큐에서 제거

            if (visited.find(vertex) == visited.end()) { // 방문하지 않은 노드라면
                visited.insert(vertex); // 방문 표시
                BFS_path.push_back(vertex); // 경로에 추가

                // 현재 노드의 이웃 노드를 큐에 추가
                vector<int> neighbors = graph.get_neighbors(vertex);
                for (int &neighbor: neighbors) {
                    if (visited.find(neighbor) == visited.end()) {
                        trace_queue.push(neighbor);
                    }
                }
            }
        }
        return BFS_path;
    }
};

int main() {
    Graph graph{}; // 그래프 객체 생성

    int num_vertices, num_edges, start_vertex = 0;
    cin >> num_vertices >> num_edges >> start_vertex; // 노드 개수, 간선 개수, 시작 노드 입력

    // 노드 추가
    for (int i = 0; i < num_vertices; i++) {
        graph.add_node(i);
    }

    // 간선 추가
    for (int i = 0; i < num_edges; i++) {
        int v1, v2 = 0;
        cin >> v1 >> v2;
        graph.add_edge(make_pair(v1, v2));
    }

    // DFS 탐색
    DFS DFS_search(graph);
    vector<int> DFS_path = DFS_search.get_DFS_path(start_vertex);
    for (int& node : DFS_path) {
        cout << node << " "; // DFS 결과 출력
    }
    cout << endl;

    // BFS 탐색
    BFS BFS_search(graph);
    vector<int> BFS_path = BFS_search.get_BFS_path(start_vertex);
    for (int& node : BFS_path) {
        cout << node << " "; // BFS 결과 출력
    }
    cout << endl;

    return 0;
}
