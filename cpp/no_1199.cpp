#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Graph {
private:
    int num_vertices;
    unordered_map<int, unordered_map<int, int>> adj;
public:
    Graph(const int& _num_vertices, const vector<vector<int>>& _adj)
        : num_vertices(_num_vertices) {
        for (int i = 0; i < _num_vertices; ++i) {
            for (int j = 0; j < _num_vertices; ++j) {
                if (_adj[i][j] > 0) {
                    adj[i][j] = _adj[i][j];
                }
            }
        }
    }

    unordered_map<int, int>& get_neighbors(const int& vertex) {
        return adj[vertex];
    }

    void remove_edge(const int& u, const int& v) {
        if (adj[u][v] > 0) {
            adj[u][v]--;
            if (adj[u][v] == 0) {
                adj[u].erase(v);
            }
        }
        if (adj[v][u] > 0) {
            adj[v][u]--;
            if (adj[v][u] == 0) {
                adj[v].erase(u);
            }
        }
    }

    bool has_edge(const int& u, const int& v) {
        return adj[u].contains(v);
    }
};

void get_euler_circuit(Graph& graph, vector<int>& euler_circuit) {
    stack<int> candidates;
    candidates.push(0);

    while (!candidates.empty()) {
        int cur_vertex = candidates.top();
        if (!graph.get_neighbors(cur_vertex).empty()) {
            int next_vertex = graph.get_neighbors(cur_vertex).begin()->first;
            candidates.push(next_vertex);
            graph.remove_edge(cur_vertex, next_vertex);
        }
        else {
            euler_circuit.push_back(cur_vertex);
            candidates.pop();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_vertices;
    cin >> num_vertices;

    vector<vector<int>> adj(num_vertices, vector<int>(num_vertices, 0));
    bool is_euler_circuit = true;

    for (int i = 0; i < num_vertices; ++i) {
        int degree = 0;
        for (int j = 0; j < num_vertices; ++j) {
            cin >> adj[i][j];
            degree += adj[i][j];
        }
        if (degree % 2 != 0) {
            is_euler_circuit = false;
        }
    }

    if (!is_euler_circuit) {
        printf("-1");
    }
    else {
        Graph graph(num_vertices, adj);
        vector<int> euler_circuit;
        get_euler_circuit(graph, euler_circuit);
        for (const int& vertex : euler_circuit) {
            printf("%d ", vertex + 1);
        }
    }

    return 0;
}