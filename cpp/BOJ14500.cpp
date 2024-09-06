#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int a1(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 3; j++) {
            result = max(given_vec[i][j] + given_vec[i][j + 1] + given_vec[i][j + 2] + given_vec[i][j + 3], result);
        }
    }
    return result;
}

int a2(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 3; i++) {
        for(int j = 0; j < m; j++) {
            result = max(given_vec[i][j] + given_vec[i + 1][j] + given_vec[i + 2][j] + given_vec[i + 3][j], result);
        }
    }
    return result;
}

int b1(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; j++) {
            result = max(given_vec[i][j] + given_vec[i][j + 1] + given_vec[i + 1][j] + given_vec[i + 1][j + 1], result);
        }
    }
    return result;
}

int c1(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < m - 1; j++) {
            result = max(given_vec[i][j] + given_vec[i + 1][j] + given_vec[i + 2][j] + given_vec[i + 2][j + 1], result);
        }
    }
    return result;
}

int c2(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 2; j++) {
            result = max(given_vec[i][j] + given_vec[i + 1][j] + given_vec[i][j + 1] + given_vec[i][j + 2], result);
        }
    }
    return result;
}

int c3(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < m - 1; j++) {
            result = max(given_vec[i][j] + given_vec[i][j + 1] + given_vec[i + 1][j + 1] + given_vec[i + 2][j + 1], result);
        }
    }
    return result;
}

int c4(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 2; j++) {
            result = max(given_vec[i + 1][j] + given_vec[i + 1][j + 1] + given_vec[i + 1][j + 2] + given_vec[i][j + 2], result);
        }
    }
    return result;
}

int c5(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < m - 1; j++) {
            result = max(given_vec[i + 2][j] + given_vec[i + 2][j + 1] + given_vec[i + 1][j + 1] + given_vec[i][j + 1], result);
        }
    }
    return result;
}

int c6(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 2; j++) {
            result = max(given_vec[i][j] + given_vec[i][j + 1] + given_vec[i][j + 2] + given_vec[i + 1][j + 2], result);
        }
    }
    return result;
}

int c7(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < m - 1; j++) {
            result = max(given_vec[i][j] + given_vec[i + 1][j] + given_vec[i + 2][j] + given_vec[i][j + 1], result);
        }
    }
    return result;
}

int c8(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 2; j++) {
            result = max(given_vec[i][j] + given_vec[i + 1][j] + given_vec[i + 1][j + 1] + given_vec[i + 1][j + 2], result);
        }
    }
    return result;
}

int d1(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < m - 1; j++) {
            result = max(given_vec[i][j] + given_vec[i + 1][j] + given_vec[i + 1][j + 1] + given_vec[i + 2][j + 1], result);
        }
    }
    return result;
}

int d2(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 2; j++) {
            result = max(given_vec[i + 1][j] + given_vec[i + 1][j + 1] + given_vec[i][j + 1] + given_vec[i][j + 2], result);
        }
    }
    return result;
}

int d3(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < m - 1; j++) {
            result = max(given_vec[i][j + 1] + given_vec[i + 1][j + 1] + given_vec[i + 1][j] + given_vec[i + 2][j], result);
        }
    }
    return result;
}

int d4(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 2; j++) {
            result = max(given_vec[i][j] + given_vec[i][j + 1] + given_vec[i + 1][j + 1] + given_vec[i + 1][j + 2], result);
        }
    }
    return result;
}

int e1(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 2; j++) {
            result = max(given_vec[i][j] + given_vec[i][j + 1] + given_vec[i][j + 2] + given_vec[i + 1][j + 1], result);
        }
    }
    return result;
}

int e2(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 2; j++) {
            result = max(given_vec[i + 1][j] + given_vec[i + 1][j + 1] + given_vec[i + 1][j + 2] + given_vec[i][j + 1], result);
        }
    }
    return result;
}

int e3(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < m - 1; j++) {
            result = max(given_vec[i][j] + given_vec[i + 1][j] + given_vec[i + 2][j] + given_vec[i + 1][j + 1], result);
        }
    }
    return result;
}

int e4(const vector<vector<int>>& given_vec, const int n, const int m) {
    int result = INT_MIN;
    for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < m - 1; j++) {
            result = max(given_vec[i][j + 1] + given_vec[i + 1][j + 1] + given_vec[i + 2][j + 1] + given_vec[i + 1][j], result);
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> my_vec(n, vector<int>(m));

    for(vector<int>& row: my_vec) {
        for(int& item: row) {
            cin >> item;
        }
    }

    cout << max({
        a1(my_vec, n, m),
        a2(my_vec, n, m),
        b1(my_vec, n, m),
        c1(my_vec, n, m),
        c2(my_vec, n, m),
        c3(my_vec, n, m),
        c4(my_vec, n, m),
        c5(my_vec, n, m),
        c6(my_vec, n, m),
        c7(my_vec, n, m),
        c8(my_vec, n, m),
        d1(my_vec, n, m),
        d2(my_vec, n, m),
        d3(my_vec, n, m),
        d4(my_vec, n, m),
        e1(my_vec, n, m),
        e2(my_vec, n, m),
        e3(my_vec, n, m),
        e4(my_vec, n, m)
    });

    return 0;
}
