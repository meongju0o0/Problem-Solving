#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Graph {
private:
    vector<vector<int>> edges;
public:
    Graph() = default;

    explicit Graph(const vector<vector<int>>& _edges) {
        edges = _edges;
    }

    [[nodiscard]] vector<int>& get_neighbors(const int& vertex) {
        return edges[vertex];
    }

    [[nodiscard]] unordered_set<int> get_all_nodes() const {
        unordered_set<int> nodes;
        for(int i = 0; i < edges.size(); i++) {
            nodes.insert(i);
        }
        return nodes;
    }
};

bool is_bipartite(Graph& graph) {
    unordered_set<int> nodes = graph.get_all_nodes();
    while(!nodes.empty()) {
        unordered_set<int> setA, setB, visited;
        queue<int> qA, qB;
        qA.push(*nodes.begin());
        while(!qA.empty() || !qB.empty()) {
            while(!qA.empty()) {
                int cur_vertex = qA.front();
                qA.pop();
                if(!visited.contains(cur_vertex)) {
                    visited.insert(cur_vertex);
                    setA.insert(cur_vertex);
                    for(const int& neighbor: graph.get_neighbors(cur_vertex)) {
                        if(setA.contains(neighbor)) {
                            return false;
                        }
                        else if(!setB.contains(neighbor)) {
                            qB.push(neighbor);
                        }
                    }
                }
            }
            while(!qB.empty()) {
                int cur_vertex = qB.front();
                qB.pop();
                if(!visited.contains(cur_vertex)) {
                    visited.insert(cur_vertex);
                    setB.insert(cur_vertex);
                    for(const int& neighbor: graph.get_neighbors(cur_vertex)) {
                        if(setB.contains(neighbor)) {
                            return false;
                        }
                        else if(!setA.contains(neighbor)) {
                            qA.push(neighbor);
                        }
                    }
                }
            }
        }
        for(const int& visited_node: visited) {
            nodes.erase(visited_node);
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++) {
        int num_vertices, num_edges;
        cin >> num_vertices >> num_edges;

        vector<vector<int>> edges(num_vertices, vector<int>(0));
        for(int j = 0; j < num_edges; j++) {
            int u, v;
            cin >> u >> v;
            edges[u-1].push_back(v-1);
            edges[v-1].push_back(u-1);
        }
        Graph graph = Graph(edges);

        cout << (is_bipartite(graph) ? "YES" : "NO") << endl;
    }

    return 0;
}