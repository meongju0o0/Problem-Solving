#include <iostream>
#include <vector>

typedef long long int64;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64 n, m;
    cin >> n >> m;

    vector<int64> v(n);
    for (int64& item: v) {
        cin >> item;
    }

    bool flag = true;
    for (const int64& item: v) {
        m -= item - 1;
        if (m <= 0) {
            flag = false;
            break;
        }
    }

    if (flag) {
        printf("OUT\n");
    }
    else {
        printf("DIMI\n");
    }

    return 0;
}