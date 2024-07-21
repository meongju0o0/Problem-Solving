#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>

using namespace std;

struct cmp {
    bool operator() (const tuple<int, int>& a, const tuple<int, int>& b) const {
        if(get<1>(a) != get<1>(b)) {
            return get<1>(a) > get<1>(b);
        }
        else {
            return get<0>(a) > get<0>(b);
        }
    }
};

class Graph {
private:
    vector<vector<tuple<int, int>>> edges;
public:
    Graph() = default;

    explicit Graph(const vector<vector<tuple<int, int>>>& _edges) {
        edges = _edges;
    }

    [[nodiscard]] vector<tuple<int, int>>& get_neighbors(const int& vertex) {
        return edges[vertex];
    }

    [[nodiscard]] int num_vertices() const {
        return static_cast<int>(edges.size());
    }
};

tuple<int, vector<int>> dijkstra(Graph& graph, const int& startVertex, const int& endVertex) {
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, cmp> candidates;
    vector<tuple<int, vector<int>>> shortest_paths(graph.num_vertices(), make_tuple(INT_MAX, vector<int>()));
    candidates.emplace(startVertex, 0);
    get<0>(shortest_paths[startVertex]) = 0;
    get<1>(shortest_paths[startVertex]).push_back(startVertex);

    while(!candidates.empty()) {
        int cur_vertex = get<0>(candidates.top());
        int cur_weight = get<1>(candidates.top());
        candidates.pop();
        if(get<0>(shortest_paths[cur_vertex]) >= cur_weight) {
            const vector<tuple<int, int>> neighbors = graph.get_neighbors(cur_vertex);
            for(const tuple<int, int>& neighbor: neighbors) {
                int next_vertex = get<0>(neighbor);
                int next_weight = get<1>(neighbor);
                if(get<0>(shortest_paths[cur_vertex]) + next_weight < get<0>(shortest_paths[next_vertex])) {
                    candidates.emplace(next_vertex, next_weight);
                    get<0>(shortest_paths[next_vertex]) = get<0>(shortest_paths[cur_vertex]) + next_weight;
                    get<1>(shortest_paths[next_vertex]) = get<1>(shortest_paths[cur_vertex]);
                    get<1>(shortest_paths[next_vertex]).push_back(next_vertex);
                }
            }
        }
    }

    return shortest_paths[endVertex];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<tuple<int, int>>> edges(n);

    for(int i = 0; i < m; i++) {
        int fromVertex, toVertex, weight;
        cin >> fromVertex >> toVertex >> weight;
        edges[fromVertex-1].emplace_back(toVertex-1, weight);
    }

    Graph graph = Graph(edges);

    int startVertex, endVertex;
    cin >> startVertex >> endVertex;

    tuple<int, vector<int>> shortest_path = dijkstra(graph, startVertex-1, endVertex-1);
    printf("%d\n%llu\n", get<0>(shortest_path), get<1>(shortest_path).size());
    for(const int& path_vertex: get<1>(shortest_path)) {
        printf("%d ", path_vertex+1);
    }

    return 0;
}