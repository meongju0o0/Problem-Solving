#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
private:
    vector<int> vertices;
    unordered_map<int, vector<int>> edges;
public:
    Graph() = default;

    Graph(int num_vertices, int num_edges, vector<int>& vertices_, unordered_map<int, vector<int>>& edges_) {
        this->vertices = std::move(vertices_);
        this->edges = std::move(edges_);
    }

    vector<int> get_vertices() {
        return vertices;
    }

    unsigned num_vertices() {
        return vertices.size();
    }

    vector<int> get_neighbors(int vertex) {
        return edges[vertex];
    }

    void print_edges() {
        for (auto & edge : edges) {
            cout << "node " << edge.first << ": ";
            for (auto& node: edge.second) {
                cout << node << " ";
            }
            cout << endl;
        }
    }
};

class KevinBaconNumber {
private:
    Graph graph;
public:
    explicit KevinBaconNumber(Graph& graph_) {
        this->graph = graph_;
    }

    int get_kevin_bacon_number(int start_vertex) {
        //Initialize queue with start vertex
        queue<int> neighbor_queue;
        unordered_map<int, int> hop_chk;
        neighbor_queue.push(start_vertex);
        hop_chk[start_vertex] = 0;

        //Start to calculate kevin_bacon_number
        while(!neighbor_queue.empty()) {
            int cur_vertex = neighbor_queue.front();
            neighbor_queue.pop();

            const vector<int> neighbors = graph.get_neighbors(cur_vertex);
            for (const int &next_vertex: neighbors) {
                if (hop_chk.find(next_vertex) == hop_chk.end()) {
                    neighbor_queue.push(next_vertex);
                    hop_chk[next_vertex] = hop_chk[cur_vertex] + 1;
                }
            }
        }

        int kevin_bacon_number = 0;
        for (auto& hop_cnt: hop_chk) {
            kevin_bacon_number += hop_cnt.second;
        }

        return kevin_bacon_number;
    }

    int get_min_kevin_bacon_number() {
        vector<int> vertices = graph.get_vertices();
        int min = INT_MAX;
        int minVertex = -1;
        for(int& vertex: vertices) {
            int kevin_bacon_number = this->get_kevin_bacon_number(vertex);
            if (kevin_bacon_number < min) {
                min = kevin_bacon_number;
                minVertex = vertex;
            }
        }
        return minVertex;
    }
};

int main() {
    //Initialize Graph
    int num_vertices, num_edges;
    scanf("%d %d", &num_vertices, &num_edges);
    vector<int> vertices(num_vertices);
    unordered_map<int, vector<int>> edges;
    for (int i = 0; i < num_vertices; i++) {
        vertices[i] = i;
    }
    for (int i = 0; i < num_edges; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        edges[v1-1].push_back(v2-1);
        edges[v2-1].push_back(v1-1);
    }
    Graph graph = Graph(num_vertices, num_edges, vertices, edges);

    //Get Minimum KevinBaconNumber
    KevinBaconNumber kevin_bacon_number_getter = KevinBaconNumber(graph);
    printf("%d", (kevin_bacon_number_getter.get_min_kevin_bacon_number() + 1));

    return 0;
}