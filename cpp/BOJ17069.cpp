#include <iostream>
#include <vector>
#include <tuple>

#define HORIZON 0
#define VERTICAL 1
#define DIAGONAL 2

typedef long long dtype;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    vector<vector<tuple<dtype, dtype, dtype>>> memo(n, vector<tuple<dtype, dtype, dtype>>(n, make_tuple(0, 0, 0)));

    for(int i = 1; i < n; i++) {
        if(!map[0][i]) {
            memo[0][i] = make_tuple(1, 0, 0);
        }
        else {
            break;
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(!map[i][j]) {
                get<HORIZON>(memo[i][j]) = get<HORIZON>(memo[i][j-1]) + get<DIAGONAL>(memo[i][j-1]);
                get<VERTICAL>(memo[i][j]) = get<VERTICAL>(memo[i-1][j]) + get<DIAGONAL>(memo[i-1][j]);
                if(!map[i-1][j] && !map[i][j-1]) {
                    get<DIAGONAL>(memo[i][j]) = get<HORIZON>(memo[i-1][j-1]) + get<VERTICAL>(memo[i-1][j-1]) + get<DIAGONAL>(memo[i-1][j-1]);
                }
            }
            else {
                memo[i][j] = make_tuple(0, 0, 0);
            }
        }
    }

    const dtype sum = get<HORIZON>(memo[n-1][n-1]) + get<VERTICAL>(memo[n-1][n-1]) + get<DIAGONAL>(memo[n-1][n-1]);
    printf("%lld", sum);

    return 0;
}