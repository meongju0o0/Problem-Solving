#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_set>

using namespace std;

map<int, int> get_parents(const vector<vector<int>>& graph) {
    map<int, int> parents;
    unordered_set<int> visited;
    stack<int> candidates;
    candidates.push(0);

    while(!candidates.empty()) {
        int cur_vertex = candidates.top();
        candidates.pop();

        if(!visited.contains(cur_vertex)) {
            visited.insert(cur_vertex);
            vector<int> neighbors = graph[cur_vertex];
            for(const int& neighbor: neighbors) {
                if(!visited.contains(neighbor)) {
                    parents[neighbor+1] = cur_vertex+1;
                    candidates.push(neighbor);
                }
            }
        }
    }

    return parents;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(0));

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[v-1].push_back(u-1);
        graph[u-1].push_back(v-1);
    }

    for(auto& parent: get_parents(graph)) {
        printf("%d\n", parent.second);
    }

    return 0;
}