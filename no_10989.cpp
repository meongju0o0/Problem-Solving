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
        if(my_map.find(item) == my_map.end()) {
            my_map[item] = 1;
        }
        else {
            my_map[item]++;
        }
    }

    string result;
    for(auto& item: my_map) {
        for(int i = 0; i < item.second; i++) {
            result += (to_string(item.first) + "\n");
        }
    }

    cout << result;

    return 0;
}