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

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        if(numbers.find(num) != numbers.end()) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }
    return 0;
}