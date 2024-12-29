#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<string> real_stuffs;
    for (int i = 0; i < n; i++) {
        string stuff;
        cin >> stuff;
        real_stuffs.insert(stuff);
    }

    unordered_set<string> used_stuffs;
    for (int i = 0; i < n - 1; i++) {
        string stuff;
        cin >> stuff;
        used_stuffs.insert(stuff);
    }

    for (const string& stuff : real_stuffs) {
        if (!used_stuffs.contains(stuff)) {
            cout << stuff;
            break;
        }
    }

    return 0;
}