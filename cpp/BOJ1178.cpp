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

int num_needed_edges(const Graph& graph) {
    priority_queue<int> odd_degree_cnts;

    //BFS Traverse
    unordered_set<int> visited;
    while(visited.size() != graph.get_num_vertices()) {
        int odd_degree_cnt = 0;
        queue<int> candidates;
        for(int i = 0; i < graph.get_num_vertices(); i++) {
            if(!visited.contains(i)) {
                candidates.push(i);
                break;
            }
        }

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
        odd_degree_cnts.push(odd_degree_cnt);
    }

    //Determine needed edges
    int needed_edges = 0;
    while(odd_degree_cnts.size() > 1){
        int odd_degree_1 = odd_degree_cnts.top();
        odd_degree_cnts.pop();
        int odd_degree_2 = odd_degree_cnts.top();
        odd_degree_cnts.pop();

        int connected_odd_degree = 0;
        if(odd_degree_1 > 0 && odd_degree_2 > 0) {
            connected_odd_degree = odd_degree_1 + odd_degree_2 - 2;
        }
        else if(odd_degree_1 > 0 && odd_degree_2 == 0) {
            connected_odd_degree = odd_degree_1 + odd_degree_2;
        }
        else if(odd_degree_1 == 0 && odd_degree_2 == 0) {
            connected_odd_degree = 2;
        }
        odd_degree_cnts.push(connected_odd_degree);

        needed_edges++;
    }
    if(odd_degree_cnts.top() > 2) {
        needed_edges += odd_degree_cnts.top() / 2 - 1;
    }

    return needed_edges;
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

    cout << num_needed_edges(graph) << endl;

    return 0;
}