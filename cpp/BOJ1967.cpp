#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Graph {
private:
    vector<vector<tuple<int, int>>> edges;
    int num_vertices;
public:
    Graph() = default;

    explicit Graph(const vector<vector<tuple<int, int>>>& _edges, const int& _num_vertices) {
        edges = _edges;
        num_vertices = _num_vertices;
    }

    [[nodiscard]] vector<tuple<int, int>>& get_neighbors(int vertex) {
        return edges[vertex];
    }

    [[nodiscard]] int get_num_vertices() const {
        return num_vertices;
    }
};

tuple<int, int> get_longest_path(Graph& graph, const int& start_vertex) {
    stack<int> candidates;
    unordered_set<int> visited;
    candidates.push(start_vertex);

    vector<int> path_lens(graph.get_num_vertices(), 0);
    path_lens[start_vertex] = 0;

    while(!candidates.empty()) {
        int cur_vertex = candidates.top();
        candidates.pop();
        if(!visited.contains(cur_vertex)) {
            visited.insert(cur_vertex);
            vector<tuple<int, int>> neighbors = graph.get_neighbors(cur_vertex);
            for(const auto& neighbor: neighbors) {
                if(!visited.contains(get<0>(neighbor)) && path_lens[get<0>(neighbor)] == 0) {
                    candidates.push(get<0>(neighbor));
                    path_lens[get<0>(neighbor)] = path_lens[cur_vertex] + get<1>(neighbor);
                }
            }
        }
    }

    return make_tuple(*ranges::max_element(path_lens.begin(), path_lens.end()),
        ranges::max_element(path_lens.begin(), path_lens.end()) - path_lens.begin());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<tuple<int, int>>> edges(n);
    for(int i = 1; i < n; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges[u-1].emplace_back(v-1, weight);
        edges[v-1].emplace_back(u-1, weight);
    }

    Graph graph = Graph(edges, n);

    cout << get<0>(get_longest_path(graph, get<1>(get_longest_path(graph, 0))));

    return 0;
}