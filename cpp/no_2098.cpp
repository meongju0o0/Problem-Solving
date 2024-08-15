#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void permutation(vector<vector<int>>& permu, int n, const vector<int> cur_permu, unordered_set<int>& visited) {
    if(cur_permu.size() == n) {
        permu.push_back(cur_permu);
    }
    else {
        for(int i = 1; i <= n; i++) {
            if(!visited.contains(i)) {
                visited.insert(i);
                vector<int> temp_permu = cur_permu;
                temp_permu.push_back(i);
                permutation(permu, n, temp_permu, visited);
                visited.erase(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> permu;
    unordered_set<int> visited;
    permutation(permu, n, vector<int>(0), visited);

    for(const vector<int>& permu_line: permu) {
        for(const int& item: permu_line) {
            printf("%d ", item);
        }
        printf("\n");
    }

    return 0;
}