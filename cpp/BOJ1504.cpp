#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <algorithm>
#include <climits>

using namespace std;

struct cmp {
    bool operator() (const tuple<int, int>& a, const tuple<int, int>& b) const {
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

    [[nodiscard]] int num_vertices() const {
        return static_cast<int>(edges.size());
    }
};

vector<int> dijkstra(Graph& graph, const int& start_vertex) {
    vector<int> weights(graph.num_vertices(), INT_MAX);
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, cmp> length_pq;
    weights[start_vertex] = 0;
    length_pq.emplace(start_vertex, 0);

    while(!length_pq.empty()) {
        const int cur_vertex = get<0>(length_pq.top());
        const int cur_weight = get<1>(length_pq.top());
        length_pq.pop();
        if(cur_weight <= weights[cur_vertex]) {
            for(const tuple<int, int>& neighbor: graph.get_neighbors(cur_vertex)) {
                const int next_vertex = get<0>(neighbor);
                const int next_weight = get<1>(neighbor);
                if(weights[next_vertex] > weights[cur_vertex] + next_weight) {
                    weights[next_vertex] = weights[cur_vertex] + next_weight;
                    length_pq.emplace(next_vertex, next_weight);
                }
            }
        }
    }

    return weights;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    vector<vector<tuple<int, int>>> edges(num_vertices);
    for(int i = 0; i < num_edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges[u-1].emplace_back(v-1, weight);
        edges[v-1].emplace_back(u-1, weight);
    }

    Graph graph = Graph(edges);

    int u, v;
    cin >> u >> v;

    const unordered_set<int> excluded_vertices = {0, u-1, v-1};
    const vector<int> start_lens = dijkstra(graph, 0);
    const vector<int> u_lens = dijkstra(graph, u-1);
    const vector<int> v_lens = dijkstra(graph, v-1);

    int start_u_len = start_lens[u-1];
    int u_v_len = u_lens[v-1];
    int v_end_len = v_lens[num_vertices - 1];
    int start_u_v_end_len;
    if(start_u_len == INT_MAX || u_v_len == INT_MAX || v_end_len == INT_MAX) {
        start_u_v_end_len = INT_MAX;
    }
    else {
        start_u_v_end_len = start_u_len + u_v_len + v_end_len;
    }

    int start_v_len = start_lens[v-1];
    int v_u_len = v_lens[u-1];
    int u_end_len = u_lens[num_vertices - 1];
    int start_v_u_end_len;
    if(start_v_len == INT_MAX || v_u_len == INT_MAX || u_end_len == INT_MAX) {
        start_v_u_end_len = INT_MAX;
    }
    else {
        start_v_u_end_len = start_v_len + v_u_len + u_end_len;
    }

    int result = min(start_u_v_end_len, start_v_u_end_len);
    if(result == INT_MAX) {
        cout << -1;
    }
    else {
        cout << result;
    }

    return 0;
}