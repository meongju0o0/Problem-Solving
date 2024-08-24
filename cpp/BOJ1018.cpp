#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int chk_color(char**& ori_mat, char**& correct_mat, int row, int col) {
    int cnt = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(ori_mat[row + i][col + j] != correct_mat[i][j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

void make_white_chess_mat(char**& mat) {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if((i + j) % 2 == 0) {
                mat[i][j] = 'W';
            }
            else {
                mat[i][j] = 'B';
            }
        }
    }
}

void make_black_chess_mat(char**& mat) {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if((i + j) % 2 == 0) {
                mat[i][j] = 'B';
            }
            else {
                mat[i][j] = 'W';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    cin.ignore();

    char** ori_mat = new char*[m];
    for(int i = 0; i < m; i++) {
        ori_mat[i] = new char[n];
    }

    for(int i = 0; i < m; i++) {
        string row;
        getline(cin, row);
        for(int j = 0; j < n; j++) {
            ori_mat[i][j] = row[j];
        }
    }

    char** white_mat = new char*[8];
    for(int i = 0; i < 8; i++) {
        white_mat[i] = new char[8];
    }
    make_white_chess_mat(white_mat);

    char** black_mat = new char*[8];
    for(int i = 0; i < 8; i++) {
        black_mat[i] = new char[8];
    }
    make_black_chess_mat(black_mat);

    int min_cnt = INT_MAX;

    for(int i = 0; i <= m - 8; i++) {
        for(int j = 0; j <= n - 8; j++) {
            int white_cnt = chk_color(ori_mat, white_mat, i, j);
            int black_cnt = chk_color(ori_mat, black_mat, i, j);
            min_cnt = min(min_cnt, min(white_cnt, black_cnt));
        }
    }

    //Print Results
    cout << min_cnt;

    //Memory Deallocation
    for(int i = 0; i < m; i++) {
        delete[] ori_mat[i];
    }
    delete[] ori_mat;

    for(int i = 0; i < 8; i++) {
        delete[] white_mat[i];
    }
    delete[] white_mat;

    for(int i = 0; i < 8; i++) {
        delete[] black_mat[i];
    }
    delete[] black_mat;

    return 0;
}
