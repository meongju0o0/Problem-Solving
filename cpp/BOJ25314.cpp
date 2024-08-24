#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const string mylong = "long ";
    int n; cin >> n;
    for(int i = 0; i < n/4; i++) cout << mylong;
    cout << "int";
    return 0;
}