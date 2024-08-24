#include <iostream>
#include <vector>

using namespace std;

void mat_mul(const vector<vector<int>>& a, const vector<vector<int>>& b, vector<vector<int>>& result) {
    //a: n x m
    //b: m x l
    const unsigned n = a.size();
    const unsigned m = b.size();
    const unsigned l = b.begin()->size();

    for(unsigned i = 0; i < n; i++) {
        for(unsigned j = 0; j < l; j++) {
            result[i][j] = 0;
            for(unsigned k = 0; k < m; k++) {
                result[i][j] = result[i][j] + a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;

    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cin >> m >> k;
    vector<vector<int>> b(m, vector<int>(k, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            cin >> b[i][j];
        }
    }

    vector<vector<int>> result(n, vector<int>(k, 0));
    mat_mul(a, b, result);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}