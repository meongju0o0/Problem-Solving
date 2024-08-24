#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long get_total_length(const vector<long long>& trees, long long length) {
    long long total_length = 0;
    for(const long long& tree: trees) {
        if(tree > length) {
            total_length += tree - length;
        }
    }
    return total_length;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    long long first = 0, mid, last = LLONG_MIN;
    vector<long long> trees(n);
    for(long long& tree: trees) {
        cin >> tree;
        if(tree > last) {
            last = tree;
        }
        if(tree < first) {
            first = tree;
        }
    }

    while(first <= last) {
        mid = (first + last) / 2;
        long long total_length = get_total_length(trees, mid);
        if(total_length < m) {
            last = mid - 1;
        }
        else if(total_length > m) {
            first = mid + 1;
        }
        else {
            break;
        }
    }

    if(get_total_length(trees, mid) < m) {
        mid--;
    }

    printf("%llu", mid);

    return 0;
}