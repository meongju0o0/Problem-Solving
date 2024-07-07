#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    int idx;
    cin >> str >> idx;

    cout << str[idx-1] << endl;

    return 0;
}