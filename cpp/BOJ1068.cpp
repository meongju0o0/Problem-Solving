#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int get_leaf_cnt(const vector<vector<int>>& adj, const int root_node, const int delete_node) {
    if(delete_node == root_node) {
        return 0;
    }
    else {
        int cnt = 0;
        stack<int> cands;
        cands.push(root_node);
        while(!cands.empty()) {
            const int cur_vertex = cands.top();
            cands.pop();
            if(adj[cur_vertex].empty() || (adj[cur_vertex].size() == 1 && adj[cur_vertex][0] == delete_node)) {
                cnt++;
            }
            else {
                for(const int neighbor: adj[cur_vertex]) {
                    if(neighbor != delete_node) {
                        cands.push(neighbor);
                    }
                }
            }
        }
        return cnt;
    }
}

int main() {
    int n;
    cin >> n;

    int root_node = 0;
    vector<vector<int>> adj(n);

    for(int i = 0; i < n; i++) {
        int parent;
        cin >> parent;
        if(parent != -1) {
            adj[parent].push_back(i);
        }
        else {
            root_node = i;
        }
    }

    int delete_node;
    cin >> delete_node;

    printf("%d", get_leaf_cnt(adj, root_node, delete_node));

    return 0;
}