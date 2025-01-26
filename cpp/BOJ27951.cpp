#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int cnt1 = 0, cnt2 = 0;
    vector<int> items(n);
    for (int& item: items) {
        cin >> item;

        if (item == 1) {
            cnt1++;
        } else if (item == 2) {
            cnt2++;
        }
    }

    int u, d;
    cin >> u >> d;

    string result;
    result.reserve(n);
    for (int i = 0; i < n; i++) {
        if (items[i] == 1) {
            if (u > 0) {
                u--;
                cnt1--;
                result += 'U';
            }
        } else if (items[i] == 2) {
            if (d > 0) {
                d--;
                cnt2--;
                result += 'D';
            }
        } else if (items[i] == 3) {
            if (u > 0 && cnt1 < u) {
                u--;
                result += 'U';
            }
            else if (d > 0 && cnt2 < d) {
                d--;
                result += 'D';
            }
            else if (u > 0) {
                u--;
                result += 'U';
            }
            else if (d > 0) {
                d--;
                result += 'D';
            }
        }
    }

    if (u == 0 && d == 0) {
        cout << "YES\n";
        cout << result << '\n';
    } else if (u > 0 || d > 0) {
        cout << "NO\n";
    }

    return 0;
}