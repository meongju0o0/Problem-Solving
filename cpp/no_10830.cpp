#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> mat_mul(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    //a: n x m
    //b: m x l
    const unsigned n = a.size();
    const unsigned m = b.size();
    const unsigned l = b.begin()->size();
    vector<vector<int>> result(n, vector<int>(l, 0));

    for(unsigned i = 0; i < n; i++) {
        for(unsigned j = 0; j < l; j++) {
            result[i][j] = 0;
            for(unsigned k = 0; k < m; k++) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % 1000;
            }
        }
    }

    return result;
}

vector<vector<int>> mat_pow(unordered_map<unsigned long long, vector<vector<int>>>& memo, vector<vector<int>>& a, const unsigned long long& pow) {
    if(memo.contains(pow)) {
        return memo[pow];
    }
    else {
        if(pow % 2 == 0) {
            memo[pow] = mat_mul(mat_pow(memo, a, pow/2), mat_pow(memo, a, pow/2));
            return memo[pow];
        }
        else {
            memo[pow] = mat_mul(mat_pow(memo, a, pow-1), a);
            return memo[pow];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    unsigned long long b;
    cin >> n >> b;
    vector<vector<int>> mat(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int num;
            cin >> num;
            mat[i][j] = num % 1000;
        }
    }

    unordered_map<unsigned long long, vector<vector<int>>> memo;
    memo[1] = mat;
    vector<vector<int>> result = mat_pow(memo, mat, b);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}