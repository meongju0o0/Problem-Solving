#include <iostream>
#include <vector>

using namespace std;

void calculate_subtree_sizes(const vector<vector<int>>& adj, vector<int>& subtree_sizes, int cur, int parent) {
    subtree_sizes[cur] = 1;
    for(const int neighbor : adj[cur]) {
        if(neighbor != parent) {
            calculate_subtree_sizes(adj, subtree_sizes, neighbor, cur);
            subtree_sizes[cur] += subtree_sizes[neighbor];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, q;
    cin >> n >> r >> q;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<int> subtree_sizes(n, 0);

    calculate_subtree_sizes(adj, subtree_sizes, r - 1, -1);

    for(int i = 0; i < q; i++) {
        int u;
        cin >> u;
        printf("%d\n", subtree_sizes[u - 1]);
    }

    return 0;
}