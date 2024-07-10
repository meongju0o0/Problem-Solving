#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, int> ranks;
    for(int i = 0; i < n; i++) {
        int rank;
        cin >> rank;
        if(ranks.contains(rank)) {
            ranks[rank]++;
        }
        else {
            ranks[rank] = 0;
        }
    }

}