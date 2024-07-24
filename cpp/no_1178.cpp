#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
private:
    unordered_map<int, unordered_set<int>> edges;
    unordered_set<int> dummy_neighbors{};
public:
    Graph() = default;

    explicit Graph(const unordered_map<int, unordered_set<int>>& _edges) {
        edges = _edges;
    }

    [[nodiscard]] int get_degree(const int& vertex) {
        return static_cast<int>(edges[vertex].size());
    }

    [[nodiscard]] unordered_set<int>& get_neighbors(const int& vertex) {
        if(edges.contains(vertex)) {
            return edges[vertex];
        }
        else {
            return dummy_neighbors;
        }
    }
};

int get_num_travels(Graph& graph, unordered_set<int>& not_visited) {
    int num_travels = 0;

    stack<int> candidates;

    while(!not_visited.empty()) {
        int partial_odd_cnt = 0;
        candidates.push(*not_visited.begin());
        while(!candidates.empty()) {
            int cur_vertex = candidates.top();
            candidates.pop();
            if(not_visited.contains(cur_vertex)) {
                not_visited.erase(cur_vertex);
                if(graph.get_degree(cur_vertex) % 2 == 1) {
                    partial_odd_cnt++;
                }
                else if(graph.get_degree(cur_vertex) == 0) {
                    partial_odd_cnt = -1;
                    break;
                }
                for(const int& neighbor: graph.get_neighbors(cur_vertex)) {
                    if(not_visited.contains(neighbor)) {
                        candidates.push(neighbor);
                    }
                }
            }
        }
        if(partial_odd_cnt == 0) {
            num_travels += 1;
        }
        else if(partial_odd_cnt > 0) {
            num_travels += partial_odd_cnt / 2;
        }
    }

    return num_travels;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    unordered_map<int, unordered_set<int>> edges;
    unordered_set<int> not_visited;

    for(int i = 0; i < num_edges; i++) {
        int from_vertex, to_vertex;
        cin >> from_vertex >> to_vertex;
        edges[from_vertex].insert(to_vertex);
        edges[to_vertex].insert(from_vertex);
        not_visited.insert(from_vertex);
        not_visited.insert(to_vertex);
    }

    Graph graph = Graph(edges);

    int num_travels = get_num_travels(graph, not_visited);
    printf("%d", num_travels);

    return 0;
}