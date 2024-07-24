#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> passwords(n);

    for(int i = 0; i < n; i++) {
        string url, pw;
        cin >> url >> pw;
        passwords[url] = pw;
    }

    for(int i = 0; i < m; i++) {
        string url;
        cin >> url;
        printf("%s\n", passwords[url].c_str());
    }

    return 0;
}