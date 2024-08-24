#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> items(n);

    for(int& item: items) {
        cin >> item;
    }

    int v;
    cin >> v;

    int cnt = 0;
    for(const int& item: items) {
        if(item == v) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}