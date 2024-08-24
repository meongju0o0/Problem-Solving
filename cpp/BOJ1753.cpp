#include <iostream>
#include <cstdio>
#include <climits>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    vector<int> vertices;
    vector<vector<pair<int, int>>> edges; // edges[fromVertex]: pair<int, int>: (toVertex, weight)
public:
    Graph() = default;

    Graph(int num_vertices, int num_edges, vector<vector<int>>& edges_) {
        vertices.resize(num_vertices);
        edges.resize(num_vertices);
        for (vector<int>& edge_ : edges_) {
            vertices[edge_[0] - 1] = edge_[0] - 1;
            edges[edge_[0] - 1].emplace_back(edge_[1] - 1, edge_[2]);
        }
    }

    unsigned num_vertices() {
        return vertices.size();
    }

    unsigned num_edges() {
        return edges.size();
    }

    [[nodiscard]] const vector<pair<int, int>>& get_neighbors(int fromVertex) const {
        return edges[fromVertex];
    }
};

class ShortestPath {
private:
    Graph graph;
    vector<int> path_store; // 각 정점의 번호에 해당하는 경로의 최단 가중치
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> neighbors_queue;

public:
    explicit ShortestPath(const Graph& graph_) : graph(graph_) {
        unsigned num_vertices = graph.num_vertices();
        path_store.resize(num_vertices, INT_MAX); // INT_MAX를 무한처럼 취급
    }

    vector<int> get_shortest_path(int start_vertex) {
        start_vertex -= 1;
        path_store[start_vertex] = 0;
        neighbors_queue.emplace(0, start_vertex);

        while (!neighbors_queue.empty()) {
            int prev_weight = neighbors_queue.top().first;
            int prev_vertex = neighbors_queue.top().second;
            neighbors_queue.pop();

            const auto& neighbors = graph.get_neighbors(prev_vertex);
            for (const auto& neighbor : neighbors) {
                int cur_vertex = neighbor.first;
                int cur_weight = prev_weight + neighbor.second;

                if (cur_weight < path_store[cur_vertex]) {
                    path_store[cur_vertex] = cur_weight;
                    neighbors_queue.emplace(cur_weight, cur_vertex);
                }
            }
        }

        return path_store;
    }
};

int main() {
    int num_vertices, num_edges;
    int start_vertex;

    scanf("%d %d", &num_vertices, &num_edges);
    scanf("%d", &start_vertex);

    vector<vector<int>> edges(num_edges, vector<int>(3));
    for (int i = 0; i < num_edges; i++) {
        int fromVertex, toVertex, weight;
        scanf("%d %d %d", &fromVertex, &toVertex, &weight);
        edges[i][0] = fromVertex;
        edges[i][1] = toVertex;
        edges[i][2] = weight;
    }

    Graph graph(num_vertices, num_edges, edges);
    ShortestPath path_getter(graph);
    vector<int> shortest_path = path_getter.get_shortest_path(start_vertex);

    for (int path : shortest_path) {
        if (path != INT_MAX) {
            printf("%d\n", path);
        } else {
            printf("INF\n");
        }
    }

    return 0;
}
