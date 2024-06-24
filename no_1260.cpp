#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Graph {
private:
    vector<int> nodes;
    vector<pair<int, int>> edges;
public:
    Graph() = default;

    void add_node(int node) {
        nodes.push_back(node);
    }

    void add_edge(pair<int, int> edge) {
        edges.push_back(edge);
    }

    vector<int> get_nodes() {
        sort(nodes.begin(), nodes.end());
        return nodes;
    }

    vector<pair<int, int>> get_edges() {
        return edges;
    }

    int num_nodes() {
        return nodes.size();
    }

    int num_edges() {
        return edges.size();
    }

    vector<int> get_neighbors(int node) {
        vector<int> neighbors;
        for (pair<int, int>& edge : edges) {
            if (edge.first == node) {
                neighbors.push_back(edge.second);
            } else if (edge.second == node) {
                neighbors.push_back(edge.first);
            }
        }
        sort(neighbors.begin(), neighbors.end());
        return neighbors;
    }
};

class DFS {
private:
    Graph graph;
    stack<int> trace_stack;
    vector<int> DFS_path;
    unordered_set<int> visited;
public:
    DFS(Graph& graph) : graph(graph) {}

    vector<int> get_DFS_path(int enter_vertex) {
        trace_stack.push(enter_vertex);

        while (!trace_stack.empty()) {
            int vertex = trace_stack.top();
            trace_stack.pop();

            if (visited.find(vertex) == visited.end()) {
                visited.insert(vertex);
                DFS_path.push_back(vertex);

                vector<int> neighbors = graph.get_neighbors(vertex);
                for (int i = neighbors.size() - 1; i >= 0; i--) {
                    if (visited.find(neighbors[i]) == visited.end()) {
                        trace_stack.push(neighbors[i]);
                    }
                }
            }
        }

        return DFS_path;
    }
};

class BFS {
private:
    Graph graph;
    queue<int> trace_queue;
    vector<int> BFS_path;
    unordered_set<int> visited;
public:
    BFS(Graph& graph) : graph(graph) {}

    vector<int> get_BFS_path(int enter_vertex) {
        trace_queue.push(enter_vertex);

        while (!trace_queue.empty()) {
            int vertex = trace_queue.front();
            trace_queue.pop();

            if (visited.find(vertex) == visited.end()) {
                visited.insert(vertex);
                BFS_path.push_back(vertex);

                vector<int> neighbors = graph.get_neighbors(vertex);
                for (int &neighbor: neighbors) {
                    if (visited.find(neighbor) == visited.end()) {
                        trace_queue.push(neighbor);
                    }
                }
            }
        }

        return BFS_path;
    }
};

int main() {
    Graph graph{};

    int num_vertices, num_edges, start_vertex = 0;
    cin >> num_vertices >> num_edges >> start_vertex;

    for (int i = 0; i < num_vertices; i++) {
        graph.add_node(i);
    }

    for (int i = 0; i < num_edges; i++) {
        int v1, v2 = 0;
        cin >> v1 >> v2;
        graph.add_edge(make_pair(v1, v2));
    }

    DFS DFS_search(graph);
    vector<int> DFS_path = DFS_search.get_DFS_path(start_vertex);
    for (int& node : DFS_path) {
        cout << node << " ";
    }
    cout << endl;

    BFS BFS_search(graph);
    vector<int> BFS_path = BFS_search.get_BFS_path(start_vertex);
    for (int& node : BFS_path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
