#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class Graph {
private:
    vector<vector<int>> edges;
public:
    Graph() = default;

    explicit Graph(const vector<vector<int>>& _edges) {
        edges = _edges;
    }

    [[nodiscard]] vector<int> get_neighbors(const int& vertex) {
        return edges[vertex];
    }
};

int num_infected_computer(Graph& graph) {
    unordered_set<int> visited;
    queue<int> candidates;
    candidates.push(0);

    while(!candidates.empty()) {
        int cur_vertex = candidates.front();
        candidates.pop();
        if(!visited.contains(cur_vertex)) {
            visited.insert(cur_vertex);
            for(const int& neighbor: graph.get_neighbors(cur_vertex)) {
                if(!visited.contains(neighbor)) {
                    candidates.push(neighbor);
                }
            }
        }
    }
    return static_cast<int>(visited.size()) - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    vector<vector<int>> edges(num_vertices);

    for(int i = 0; i < num_edges; i++) {
        int u, v;
        cin >> u >> v;
        edges[u-1].push_back(v-1);
        edges[v-1].push_back(u-1);
    }

    Graph graph = Graph(edges);

    printf("%d", num_infected_computer(graph));

    return 0;
}