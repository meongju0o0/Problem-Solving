#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Graph {
private:
    vector<vector<int>> edges;
public:
    Graph() = default;

    explicit Graph(vector<vector<int>>& edges) {
        this->edges = edges;
    }

    vector<int> get_neighbors(int vertex) {
        return edges[vertex];
    }
};

unordered_set<int> get_BFS_path(Graph& graph, int start_vertex) {
    queue<int> candidates;
    unordered_set<int> visited;
    candidates.push(start_vertex);

    while(!candidates.empty()) {
        int cur_vertex = candidates.front();
        candidates.pop();
        if(visited.find(cur_vertex) == visited.end()) {
            visited.insert(cur_vertex);
            vector<int> neighbors = graph.get_neighbors(cur_vertex);
            for(const int& neighbor: neighbors) {
                if(visited.find(neighbor) == visited.end()) {
                    candidates.push(neighbor);
                }
            }
        }
    }

    return visited;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    vector<vector<int>> edges(num_vertices, vector<int>(0));
    for(int i = 0; i < num_edges; i++) {
        int u, v;
        cin >> u >> v;
        edges[u-1].push_back(v-1);
        edges[v-1].push_back(u-1);
    }

    Graph graph = Graph(edges);

    unordered_set<int> accumulate_not_visited;
    for(int i = 0; i < num_vertices; i++) {
        accumulate_not_visited.insert(i);
    }

    int cnt = 0;
    while(!accumulate_not_visited.empty()) {
        cnt++;
        unordered_set<int> visited = get_BFS_path(graph, *accumulate_not_visited.begin());
        for(const int& visited_: visited) {
            accumulate_not_visited.erase(visited_);
        }
    }

    cout << cnt;

    return 0;
}