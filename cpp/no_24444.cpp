#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

struct cmp {
    bool operator() (const int& a, const int& b) const {
        return a < b;
    }
};

class Graph {
private:
    vector<set<int, cmp>> edges;
public:
    Graph() = default;

    explicit Graph(const vector<set<int, cmp>>& _edges) {
        edges = _edges;
    }

    [[nodiscard]] unsigned get_num_vertices() const {
        return edges.size();
    }

    [[nodiscard]] set<int, cmp> get_neighbors(const int& vertex) {
        return edges[vertex];
    }
};

vector<int> bfs(Graph& graph, const int& start_vertex) {
    //Postcondition
    int cnt = 0;
    vector<int> dfs_path(graph.get_num_vertices(), 0);

    //DFS Traverse
    queue<int> candidates;
    unordered_set<int> visited;

    candidates.push(start_vertex);
    while(!candidates.empty()) {
        int cur_vertex = candidates.front();
        candidates.pop();
        if(!visited.contains(cur_vertex)) {
            visited.insert(cur_vertex);
            dfs_path[cur_vertex] = ++cnt;
            for(const int& neighbor: graph.get_neighbors(cur_vertex)) {
                if(!visited.contains(neighbor)) {
                    candidates.push(neighbor);
                }
            }
        }
    }

    return dfs_path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_vertices, num_edges, start_vertex;
    cin >> num_vertices >> num_edges >> start_vertex;

    vector<set<int, cmp>> edges(num_vertices);

    for(int i = 0; i < num_edges; i++) {
        int u, v;
        cin >> u >> v;
        edges[u-1].insert(v-1);
        edges[v-1].insert(u-1);
    }

    Graph graph = Graph(edges);

    vector<int> bfs_path = bfs(graph, start_vertex - 1);

    for(const int& visit_order: bfs_path) {
        printf("%d\n", visit_order);
    }

    return 0;
}