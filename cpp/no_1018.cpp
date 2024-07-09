#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool chk_color(char**& mat, char color, int i, int j) {
    if(mat[i-1][j] == color && mat[i+1][j] == color && mat[i][j-1] == color && mat[i][j+1] == color) {
        return false;
    }
    else {
        return true;
    }
}

int make_chess_mat(char**& mat, int m, int n) {
    int cnt = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(!chk_color(mat, mat[i][j], i, j)) {
                cnt++;
                if(mat[i][j] == 'B') {
                    mat[i][j] = 'W';
                }
                else if(mat[i][j] == 'W') {
                    mat[i][j] = 'B';
                }
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    cin.ignore();

    char** arr = new char*[m+2];
    for(int i = 0; i < m+2; i++) {
        arr[i] = new char[n+2];
        for(int j = 0; j < n+2; j++) {
            arr[i][j] = 'X';
        }
    }

    for(int i = 0; i < m; i++) {
        string row;
        getline(cin, row);
        for(int j = 0; j < n; j++) {
            arr[i+1][j+1] = row[j];
        }
    }

    cout << make_chess_mat(arr, m, n);

    for(int i = 0; i < m+2; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
