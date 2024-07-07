#include <iostream>

using namespace std;

int GCD(int a, int b) {
    if(b == 0) {
        return a;
    }
    else {
        return GCD(b, a % b);
    }
}

int main() {
    int a, b;
    cin >> a >> b;

    int gcd;
    int lcm;
    if(a > b) {
        gcd = GCD(a, b);
    }
    else {
        gcd = GCD(b, a);
    }
    lcm = a * b / gcd;

    cout << gcd << endl;
    cout << lcm << endl;

    return 0;
}