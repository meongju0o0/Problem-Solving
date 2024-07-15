#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> accumulated_numbers(n+2, vector<int>(n+2, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int number;
            cin >> number;
            accumulated_numbers[i][j] = number + accumulated_numbers[i-1][j] + accumulated_numbers[i][j-1] - accumulated_numbers[i-1][j-1];
        }
    }

    for(int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        printf("%d\n", accumulated_numbers[x2][y2] - accumulated_numbers[x1-1][y2] - accumulated_numbers[x2][y1-1] + accumulated_numbers[x1-1][y1-1]);
    }

    return 0;
}