#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<unsigned long long> roads(n-1);
    for(unsigned long long& road: roads) {
        cin >> road;
    }

    unsigned long long oil_price;
    unsigned long long min_price = ULLONG_MAX;
    unsigned long long total_price = 0;
    for(int i = 0; i < n - 1; i++) {
        cin >> oil_price;
        if(oil_price < min_price) {
            min_price = oil_price;
        }
        total_price += min_price * roads[i];
    }

    printf("%llu", total_price);

    return 0;
}