#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
private:
    int num_vertices = 0;
    int num_edges = 0;
    unordered_map<int, unordered_set<int>> edges;
public:
    Graph() = default;

    explicit Graph(const int& _num_vertices, const int& _num_edges, const unordered_map<int, unordered_set<int>>& _edges) {
        num_vertices = _num_vertices;
        num_edges = _num_edges;
        edges = _edges;
    }

    [[nodiscard]] int get_num_vertices() const {
        return num_vertices;
    }

    [[nodiscard]] int get_num_edges() const {
        return num_edges;
    }

    [[nodiscard]] int get_start_vertex() { //O(V) Complexity
        for(int i = 0; i < num_vertices; i++) {
            int degree = this->get_degree(i);
            if(degree == 1 || degree == 3) {
                return i;
            }
        }
        return edges.begin()->first;
    }

    [[nodiscard]] int get_degree(const int& vertex) {
        if(edges.contains(vertex)) {
            return static_cast<int>(edges[vertex].size());
        }
        else {
            return 0;
        }
    }

    [[nodiscard]] unordered_set<int> get_neighbors(const int& vertex) { //O(1) Complexity
        if(edges.contains(vertex)) {
            return edges[vertex];
        }
        else {
            return unordered_set<int>{};
        }
    }

    void remove_edge(const int& from_vertex, const int& to_vertex) { //O(1) Complexity
        edges[from_vertex].erase(to_vertex);
        edges[to_vertex].erase(from_vertex);
        if(this->get_degree(from_vertex) == 0) {
            edges.erase(from_vertex);
            num_vertices--;
        }
        if(this->get_degree(to_vertex) == 0) {
            edges.erase(to_vertex);
            num_vertices--;
        }
        num_edges--;
    }
};

int num_travel(Graph& graph) {
    stack<int> candidates;
    unordered_set<int> visited;

    int cnt = 0;
    while(graph.get_num_edges() > 0) {
        cnt++;
        candidates.push(graph.get_start_vertex());
        while(!candidates.empty()) {
            int cur_vertex = candidates.top();
            candidates.pop();
            visited.insert(cur_vertex);
            for(const int& neighbor: graph.get_neighbors(cur_vertex)) {
                candidates.push(neighbor);
                graph.remove_edge(cur_vertex, neighbor);
                break;
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    unordered_map<int, unordered_set<int>> edges;

    for(int i = 0; i < num_edges; i++) {
        int from_vertex, to_vertex;
        cin >> from_vertex >> to_vertex;
        edges[from_vertex].insert(to_vertex);
        edges[to_vertex].insert(from_vertex);
    }

    Graph graph = Graph(num_vertices, num_edges, edges);

    printf("%d", num_travel(graph));

    return 0;
}