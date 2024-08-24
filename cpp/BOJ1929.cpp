#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<int> prime_numbers;
    unordered_set<int> not_prime_numbers;

    for(int i = 2; i <= n; i++) {
        if(!not_prime_numbers.contains(i)) {
            if(i >= m) {
                prime_numbers.push_back(i);
            }
            for(int j = i*2; j <= n; j += i) {
                not_prime_numbers.insert(j);
            }
        }
    }

    for(const int& prime_number: prime_numbers) {
        printf("%d\n", prime_number);
    }

    return 0;
}