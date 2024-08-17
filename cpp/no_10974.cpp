#include <iostream>
#include <vector>
#include <string>

using namespace std;

void permutation(vector<bool>& visited, const string& cur_permu, const int n) {
    if(cur_permu.size() == 2 * n) {
        printf("%s\n", cur_permu.c_str());
    }
    else {
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                visited[i] = true;
                permutation(visited, cur_permu + to_string(i) + " ", n);
                visited[i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> visited(n, false);
    permutation(visited, "", n);

    return 0;
}