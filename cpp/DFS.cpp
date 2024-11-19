#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void recursive_dfs(vector<bool>& visited, const vector<vector<int>>& adj_list, const int cur_vertex) {
    if(!visited[cur_vertex]) { // 방문한 적이 없는 정점이라면 탐색
        visited[cur_vertex] = true; // 방문했다는 것을 기록
        printf("%d ", cur_vertex); // 현재 정점을 출력
        for(const int neighbor: adj_list[cur_vertex]) { // 현재 정점의 모든 이웃에 대해
            if(!visited[neighbor]) { // 방문한 적이 없는 이웃이라면(재귀 호출 횟수를 줄이기 위함)
                recursive_dfs(visited, adj_list, neighbor); // 재귀적으로 깊이 우선 탐색
            }
        }
    }
}

void iterative_dfs(const vector<vector<int>>& adj_list, const int start_vertex) {
    stack<int> cands;
    vector<bool> visited(adj_list.size());
    cands.push(start_vertex);

    while(!cands.empty()) { // 스택이 비어있지 않은 동안
        const int cur_vertex = cands.top(); // 스택의 맨 위 정점을 꺼내옴
        cands.pop();
        if(!visited[cur_vertex]) { // 방문한 적이 없는 정점이라면
            visited[cur_vertex] = true; // 방문했다는 것을 기록
            printf("%d ", cur_vertex); // 현재 정점을 출력
            for(const int neighbor: adj_list[cur_vertex]) { // 현재 정점의 모든 이웃에 대해
                if(!visited[neighbor]) { // 방문한 적이 없는 이웃이라면
                    cands.push(neighbor); // 스택에 넣어줌
                }
            }
        }
    }
}

void iterative_bfs(const vector<vector<int>>& adj_list, const int start_vertex) {
    queue<int> cands;
    vector<bool> visited(adj_list.size());
    cands.push(start_vertex);

    while(!cands.empty()) { // 큐가 비어있지 않은 동안
        const int cur_vertex = cands.front(); // 큐의 맨 앞 정점을 꺼내옴
        cands.pop();
        if(!visited[cur_vertex]) { // 방문한 적이 없는 정점이라면
            visited[cur_vertex] = true; // 방문했다는 것을 기록
            printf("%d ", cur_vertex); // 현재 정점을 출력
            for(const int neighbor: adj_list[cur_vertex]) { // 현재 정점의 모든 이웃에 대해
                if(!visited[neighbor]) { // 방문한 적이 없는 이웃이라면
                    cands.push(neighbor); // 큐에 넣어줌
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream infile("./test_case/test_case.txt");

    int num_vertices, num_edges, start_vertex;
    cin >> num_vertices >> num_edges >> start_vertex;
    vector<vector<int>> adj_list(num_vertices, vector<int>(0));

    for(int i = 0; i < num_edges; i++) {
        int u, v;
        cin >> u >> v;

        adj_list[u - 1].push_back(v - 1);
        adj_list[v - 1].push_back(u - 1);
    }

    printf("Recursive DFS: ");
    vector<bool> visited(num_vertices);
    recursive_dfs(visited, adj_list, start_vertex - 1);
    printf("\n");

    printf("Iterative DFS: ");
    iterative_dfs(adj_list, start_vertex - 1);

    return 0;
}