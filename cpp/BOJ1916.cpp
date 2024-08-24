#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>

using namespace std;

struct cmp {
    bool operator() (const tuple<int, int>& a, const tuple<int, int>& b) {
        return get<1>(a) > get<1>(b);
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

    [[nodiscard]] unsigned num_vertices() const {
        return edges.size();
    }
};

int dijkstra(Graph& graph, int start_vertex, int end_vertex) {
    start_vertex -= 1;
    end_vertex -= 1;

    priority_queue<tuple<int, int>, vector<tuple<int, int>>, cmp> candidates;
    candidates.emplace(start_vertex, 0);

    vector<int> path_lens(graph.num_vertices(), INT_MAX);
    path_lens[start_vertex] = 0;

    while(!candidates.empty()) {
        int cur_vertex = get<0>(candidates.top());
        int cur_weight = get<1>(candidates.top());
        candidates.pop();
        if(cur_weight <= path_lens[cur_vertex]) {
            const vector<tuple<int, int>> neighbors = graph.get_neighbors(cur_vertex);
            for(const tuple<int, int>& neighbor: neighbors) {
                if(path_lens[cur_vertex] + get<1>(neighbor) < path_lens[get<0>(neighbor)]) {
                    candidates.push(neighbor);
                    path_lens[get<0>(neighbor)] = path_lens[cur_vertex] + get<1>(neighbor);
                }
            }
        }
    }

    return path_lens[end_vertex];
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
    Graph graph(edges);

    int start_vertex, end_vertex;
    cin >> start_vertex >> end_vertex;

    cout << dijkstra(graph, start_vertex, end_vertex);

    return 0;
}