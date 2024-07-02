#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Graph {
private:
    int num_vertices = 0;
    vector<vector<int>> adj_mat{};
public:
    Graph() = default;

    Graph(int num_vertices, vector<vector<int>>& adj_mat) {
        this->num_vertices = num_vertices;
        this->adj_mat = adj_mat;
    }

    vector<int> get_neighbors(int vertex) {
        vector<int> neighbors;
        for(int i = 0; i < num_vertices; i++) {
            if(adj_mat[vertex][i] == 1) {
                neighbors.push_back(i);
            }
        }
        return neighbors;
    }
};

class Path {
private:
    Graph graph{};
public:
    explicit Path(Graph& graph) {
        this->graph = graph;
    }

    void is_path_exist(int start_vertex, vector<vector<int>>& visited_mat) {
        unordered_set<int> visited;
        queue<int> candidates;

        vector<int> neighbors = graph.get_neighbors(start_vertex);
        for(int& neighbor: neighbors) {
            candidates.push(neighbor);
            visited_mat[start_vertex][neighbor] = 1;
        }
        neighbors.clear();

        while(!candidates.empty()) {
            int cur_vertex = candidates.front();
            candidates.pop();

            if(visited.find(cur_vertex) == visited.end()) {
                visited.insert(cur_vertex);
                neighbors = graph.get_neighbors(cur_vertex);
                for(int& neighbor: neighbors) {
                    if(visited.find(neighbor) == visited.end()) {
                        candidates.push(neighbor);
                        visited_mat[start_vertex][neighbor] = 1;
                    }
                }
                neighbors.clear();
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj_mat(n, vector<int>(n, 0));
    vector<vector<int>> visited_mat(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adj_mat[i][j];
        }
    }
    Graph graph(n, adj_mat);


    Path path_getter(graph);
    for(int i = 0; i < n; i++) {
        path_getter.is_path_exist(i, visited_mat);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << visited_mat[i][j] << " ";
        }
        cout << endl;
    }

    adj_mat.clear();
    adj_mat.shrink_to_fit();
    visited_mat.clear();
    visited_mat.shrink_to_fit();

    return 0;
}