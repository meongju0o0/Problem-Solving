#include <iostream>
#include <vector>
#include <tuple>

enum Directions {HORIZON, VERTICAL, DIAGONAL};

typedef long long dtype;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n, false)); // 주어진 지도를 저장
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> map[i][j];

    vector<vector<tuple<dtype, dtype, dtype>>> memo(n, vector<tuple<dtype, dtype, dtype>>(n, make_tuple(0, 0, 0)));
    // 메모 테이블 생성
    // 2차원 벡터로, 벡터의 각 아이템은 수평으로부터 온 경로의 수, 직각으로부터 온 경로의 수, 대각으로부터 온 경로의 수를 저장

    for(int i = 1; i < n; i++) {
        if(!map[0][i])
            memo[0][i] = make_tuple(1, 0, 0);
        else
            break;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(!map[i][j]) { // 현재 위치가 1이 아닌 경우(벽이 없는 경우)
                get<HORIZON>(memo[i][j]) = get<HORIZON>(memo[i][j-1]) + get<DIAGONAL>(memo[i][j-1]);
                // 현재 수평방향으로 들어온 경로의 수는 (직전에 수평으로 들어온 경로 수 + 직전에 대각으로 들어온 경로의 수)
                get<VERTICAL>(memo[i][j]) = get<VERTICAL>(memo[i-1][j]) + get<DIAGONAL>(memo[i-1][j]);
                // 현재 직각방향으로 들어온 경로의 수는 (직전에 직각으로 들어온 경로 수 + 직전에 대각으로 들어온 경로의 수)
                if(!map[i-1][j] && !map[i][j-1]) { // 대각방향으로 들어올 수 있는 경우(벽 위치 추가 확인 필요)
                    get<DIAGONAL>(memo[i][j]) = get<HORIZON>(memo[i-1][j-1]) + get<VERTICAL>(memo[i-1][j-1]) + get<DIAGONAL>(memo[i-1][j-1]);
                    // 현재 대각방향으로 들어온 경로의 수는 (직전에 직각으로 들어온 경로 수 + 직전에 수평으로 들어온 경로 수 + 직전에 대각으로 들어온 경로 수)
                }
            }
            else { // 벽이 있는 경우
                memo[i][j] = make_tuple(0, 0, 0); // 현재 위치의 경로 수는 0
            }
        }
    }

    const dtype sum = get<HORIZON>(memo[n-1][n-1]) + get<VERTICAL>(memo[n-1][n-1]) + get<DIAGONAL>(memo[n-1][n-1]);
    printf("%lld", sum);

    return 0;
}



