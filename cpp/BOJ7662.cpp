#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        map<int, int> pq;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            char command;
            int num;
            cin >> command >> num;

            if (command == 'I') {
                if (pq.contains(num)) {
                    pq[num]++;
                }
                else {
                    pq[num] = 1;
                }
            } else if (command == 'D') {
                if (pq.empty()) {
                    continue;
                }
                else if (num == 1) {
                    auto it = --pq.end();
                    if (it->second == 1) {
                        pq.erase(it);
                    }
                    else {
                        it->second--;
                    }
                }
                else if (num == -1) {
                    auto it = pq.begin();
                    if (it->second == 1) {
                        pq.erase(it);
                    }
                    else {
                        it->second--;
                    }
                }
            }
        }
        if (pq.empty()) {
            cout << "EMPTY" << endl;
        }
        else {
            cout << (--pq.end())->first << " " << pq.begin()->first << endl;
        }
    }

    return 0;
}
