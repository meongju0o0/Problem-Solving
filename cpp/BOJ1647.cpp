#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct cmp {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second > b.second;
    }
};

class Graph {
private:
    vector<vector<pair<int, int>>> edges;
    int num_vertices;
public:
    explicit Graph(const vector<vector<pair<int, int>>>& _edges, const int _num_vertices) {
        edges = _edges;
        num_vertices = _num_vertices;
    }

    [[nodiscard]] vector<pair<int, int>>& get_neighbors(const int vertex) {
        return edges[vertex];
    }

    [[nodiscard]] int get_num_vertices() const {
        return num_vertices;
    }
};

int get_mst_weight(Graph& graph) {
    int max_weight = INT_MIN;
    int mst_weight = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> candidates;
    vector<bool> visited(graph.get_num_vertices(), false);
    for(const pair<int, int>& neighbor: graph.get_neighbors(0)) {
        candidates.emplace(neighbor);
    }
    visited[0] = true;

    while(!candidates.empty()) {
        const int cur_vertex = candidates.top().first;
        const int cur_weight = candidates.top().second;
        candidates.pop();
        if(!visited[cur_vertex]) {
            visited[cur_vertex] = true;
            mst_weight += cur_weight;
            if(max_weight < cur_weight) {
                max_weight = cur_weight;
            }
            for(const pair<int, int>& neighbor: graph.get_neighbors(cur_vertex)) {
                if(!visited[neighbor.first]) {
                    candidates.emplace(neighbor);
                }
            }
        }
    }

    return mst_weight - max_weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    vector<vector<pair<int, int>>> edges(num_vertices);

    for(int i = 0; i < num_edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u - 1].emplace_back(v - 1, w);
        edges[v - 1].emplace_back(u - 1, w);
    }

    Graph graph = Graph(edges, num_vertices);

    printf("%d", get_mst_weight(graph));

    return 0;
}