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

    explicit Graph(const vector<vector<int>>& _edges) {
        edges = _edges;
    }

    [[nodiscard]] unsigned get_num_vertices() const {
        return edges.size();
    }

    [[nodiscard]] unsigned get_degree(const int& vertex) const {
        return edges[vertex].size();
    }

    [[nodiscard]] vector<int> get_neighbors(const int& vertex) const {
        return edges[vertex];
    }
};

bool is_euler_path_exist(const Graph& graph) {
    int odd_degree_cnt = 0; //Postcondition

    //BFS Traverse
    queue<int> candidates;
    unordered_set<int> visited;
    candidates.push(0);

    while(!candidates.empty()) {
        int cur_vertex = candidates.front();
        candidates.pop();
        if(!visited.contains(cur_vertex)) {
            visited.insert(cur_vertex);
            if(graph.get_degree(cur_vertex) % 2 == 1) {
                odd_degree_cnt++;
            }
            for(int& neighbor: graph.get_neighbors(cur_vertex)) {
                if(!visited.contains(neighbor)) {
                    candidates.push(neighbor);
                }
            }
        }
    }

    //Check Eulerian Path Property
    if(visited.size() == graph.get_num_vertices()) {
        if(odd_degree_cnt == 0 || odd_degree_cnt == 2) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
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

    cout << (is_euler_path_exist(graph) ? "YES" : "NO") << endl;

    return 0;
}