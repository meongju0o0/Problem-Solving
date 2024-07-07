#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, int> my_map;

    for(int i = 0; i < n; i++) {
        int item;
        cin >> item;
        if(my_map.contains(item)) {
            my_map[item]++;
        }
        else {
            my_map[item] = 1;
        }
    }

    for(pair<const int, int>& item: my_map) {
        for(int i = 0; i < item.second; i++) {
            printf("%d\n", item.first);
        }
    }

    return 0;
}