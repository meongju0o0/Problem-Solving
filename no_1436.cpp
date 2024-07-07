#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int cnt = 0;
    for(unsigned i = 0; true; i++) {
        if(to_string(i).find("666") != string::npos) {
            cnt++;
        }
        if(cnt == n) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}