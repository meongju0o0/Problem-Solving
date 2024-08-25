#include <iostream>
#include <string>
#include <vector>

using namespace std;

void bt(const int& n, const int m, vector<int> cur_progression) {
    if(cur_progression.size() == m) {
        for(const int& item: cur_progression) {
            printf("%d ", item);
        }
        printf("\n");
    }
    else {
        for(int i = 1; i <= n; i++) {
            cur_progression.push_back(i);
            bt(n, m, cur_progression);
            cur_progression.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    bt(n, m, vector<int>(0));

    return 0;
}