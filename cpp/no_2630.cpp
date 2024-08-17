#include <iostream>
#include <vector>

using namespace std;

bool chk_is_all_white(const vector<vector<int>>& paper, int x, int y, int n) {
    for(int i = x; i < x + n; i++) {
        for(int j = y; j < y + n; j++) {
            if(paper[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

bool chk_is_all_blue(const vector<vector<int>>& paper, int x, int y, int n) {
    for(int i = x; i < x + n; i++) {
        for(int j = y; j < y + n; j++) {
            if(paper[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void cut_paper(int& num_white_papers, int& num_blue_papers, const vector<vector<int>>& paper, int x, int y, int n) {
    if(chk_is_all_white(paper, x, y, n)) {
        num_white_papers++;
    }
    else if(chk_is_all_blue(paper, x, y, n)) {
        num_blue_papers++;
    }
    else {
        cut_paper(num_white_papers, num_blue_papers, paper, x, y, n/2);
        cut_paper(num_white_papers, num_blue_papers, paper, x, y + n/2, n/2);
        cut_paper(num_white_papers, num_blue_papers, paper, x + n/2, y, n/2);
        cut_paper(num_white_papers, num_blue_papers, paper, x + n/2, y + n/2, n/2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> paper(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    int num_white_papers = 0;
    int num_blue_papers = 0;

    cut_paper(num_white_papers, num_blue_papers, paper, 0, 0, n);

    printf("%d\n%d", num_white_papers, num_blue_papers);

    return 0;
}
