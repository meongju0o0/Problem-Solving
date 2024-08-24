#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> numbers;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers.insert(num);
    }

    for(const int& num: numbers) {
        printf("%d\n", num);
    }

    return 0;
}