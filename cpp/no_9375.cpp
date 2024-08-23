#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        unordered_map<string, int> mymap;

        while(n--) {
            string _, key;
            cin >> _ >> key;
            mymap[key]++;
        }

        int result = 1;
        for(auto& [key, cnt]: mymap) {
            result *= (cnt + 1);
        }

        printf("%d\n", result - 1);
    }
}