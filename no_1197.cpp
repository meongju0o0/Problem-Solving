#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct cmp {
    bool operator() (tuple<int, int>& x, tuple<int, int>& y) {
        return get<1>(x) > get<1>(y);
    }
};

class Graph {
private:
    vector<vector<tuple<int, int>>> edges;
public:
    Graph() = default;

    explicit Graph(vector<vector<tuple<int, int>>>& edges) {
        this->edges = edges;
    }

    vector<tuple<int, int>> get_neighbors(int vertex) {
        return edges[vertex];
    };
};

int get_MST_weight(Graph& graph) {
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, cmp> candidates;
    unordered_set<int> visited;

    int start_vertex = 0;
    vector<tuple<int, int>> start_neighbors = graph.get_neighbors(start_vertex);
    visited.insert(start_vertex);
    for(tuple<int, int> neighbor: start_neighbors) {
        candidates.emplace(get<0>(neighbor), get<1>(neighbor));
    }

    int mst_weight = 0;
    while(!candidates.empty()) {
        int cur_vertex = get<0>(candidates.top());
        int cur_weight = get<1>(candidates.top());
        candidates.pop();
        if(visited.find(cur_vertex) == visited.end()) {
            mst_weight += cur_weight;
            visited.insert(cur_vertex);
            vector<tuple<int, int>> neighbors = graph.get_neighbors(cur_vertex);
            for(tuple<int, int> neighbor: neighbors) {
                if(visited.find(get<0>(neighbor)) == visited.end()) {
                    candidates.emplace(get<0>(neighbor), get<1>(neighbor));
                }
            }
        }
    }

    return mst_weight;
}

int main() {
    ios::sync_with_stdio();
    cin.tie(nullptr);

    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    vector<vector<tuple<int, int>>> edges(num_vertices, vector<tuple<int, int>>(0));

    for(int i = 0; i < num_edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges[u-1].emplace_back(v-1, weight);
        edges[v-1].emplace_back(u-1, weight);
    }

    Graph graph = Graph(edges);

    cout << get_MST_weight(graph) << endl;

    return 0;
}