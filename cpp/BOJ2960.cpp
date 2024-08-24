#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    unordered_set<int> not_prime_set;

    int cnt = 0;
    for(int i = 2; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            if(!not_prime_set.contains(j)) {
                not_prime_set.insert(j);
                if(++cnt == k) {
                    cout << j << endl;
                    return 0;
                }
            }
        }
    }
}