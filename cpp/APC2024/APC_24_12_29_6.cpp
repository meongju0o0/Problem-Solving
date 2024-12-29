#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF (-1)

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, C;
    cin >> N >> M >> C;

    int Sr, Sc;
    cin >> Sr >> Sc;

    vector<vector<int>> cave(N+2, vector<int>(M+2, -1));
    for(int r=1; r<=N; r++){
        for(int c_=1; c_<=M; c_++){
            cin >> cave[r][c_];
        }
    }

    vector<vector<int>> dist(N+2, vector<int>(M+2, INF));
    dist[Sr][Sc] = 0;

    queue<pair<int,int>> q;
    q.emplace(Sr, Sc);

    while (!q.empty()){
        auto [cr, cc] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nr = cr + dy[i];
            int nc = cc + dx[i];

            if (nr < 1 || nr > N || nc < 1 || nc > M) {
                continue;
            }
            if (cave[nr][nc] != -1 && dist[nr][nc] == INF){
                dist[nr][nc] = dist[cr][cc] + 1;
                q.emplace(nr, nc);
            }
        }
    }

    int maxDist = N * M;
    vector<long long> distCount(maxDist + 1, 0LL);

    for (int r=1; r<=N; r++){
        for (int c_=1; c_<=M; c_++){
            int d = dist[r][c_];
            if (d != INF) {
                distCount[d] += cave[r][c_];
            }
        }
    }

    for (int d=1; d<=maxDist; d++){
        distCount[d] += distCount[d-1];
    }

    long long ans = 0;
    for (int L=0; L <= maxDist; L++){
        long long T = distCount[L];
        long long cost = 1LL * L * C;
        long long profit = T - cost;
        if (profit > ans) {
            ans = profit;
        }
    }

    cout << ans << "\n";
    return 0;
}
