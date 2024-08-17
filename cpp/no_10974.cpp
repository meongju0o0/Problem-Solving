#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

void permutation(vector<string>& permu, unordered_set<int>& visited, const string& cur_permu, const int n) {
    if(cur_permu.size() == 2 * n) {
        printf("%s\n", cur_permu.c_str());
    }
    else {
        for(int i = 1; i <= n; i++) {
            if(!visited.contains(i)) {
                visited.insert(i);
                permutation(permu, visited, cur_permu + to_string(i) + " ", n);
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

    vector<string> permu;
    unordered_set<int> visited;
    permutation(permu, visited, "", n);

    return 0;
}