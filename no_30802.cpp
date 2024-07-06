#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    double s, m, l, xl, xxl, xxxl;
    int t, p;
    cin >> n;
    cin >> s >> m >> l >> xl >> xxl >> xxxl;
    cin >> t >> p;

    cout << int(ceil(s/t) + ceil(m/t) + ceil(l/t) + ceil(xl/t) + ceil(xxl/t) + ceil(xxxl/t)) << endl;
    cout << n/p << " " << n%p << endl;

    return 0;
}