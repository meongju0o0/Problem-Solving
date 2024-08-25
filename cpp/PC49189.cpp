#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <climits>

using namespace std;

class Graph {
private:
    vector<vector<int>> edges;
public:
    explicit Graph(vector<vector<int>>& _edges) {
        edges = _edges;
    }
    
    [[nodiscard]] vector<int>& get_neighbors(int vertex) {
        return edges[vertex];
    }
    
    [[nodiscard]] int get_num_vertices() {
        return edges.size();
    }
};

int get_num_longest_path(Graph& graph) {
    int max_path_len = 0;
    vector<int> path_lens(graph.get_num_vertices(), INT_MAX);
    path_lens[0] = 0;

    queue<int> candidates;
    unordered_set<int> visited;
    
    candidates.push(0);
    while(!candidates.empty()) {
        const int cur_vertex = candidates.front();
        candidates.pop();
        for(const int& neighbor: graph.get_neighbors(cur_vertex)) {
            if(path_lens[cur_vertex] + 1 < path_lens[neighbor]) {
                path_lens[neighbor] = path_lens[cur_vertex] + 1;
                candidates.push(neighbor);
                if(max_path_len < path_lens[neighbor]) {
                    max_path_len = path_lens[neighbor];
                }
            }
        }
    }
    
    int cnt = 0;
    for(const int& path_len: path_lens) {
        if(max_path_len == path_len) {
            cnt++;
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> coo_mat) {
    int answer = 0;
    
    vector<vector<int>> edges(n, vector<int>(0));
    for(vector<int> edge: coo_mat) {
        int u = edge[0]; --u;
        int v = edge[1]; --v;
        
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    Graph graph = Graph(edges);
    
    answer = get_num_longest_path(graph);
    
    return answer;
}