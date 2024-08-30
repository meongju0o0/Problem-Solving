#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    auto begin_it = str.begin();
    auto end_it = str.end();
    --end_it;

    while(begin_it < end_it) {
        if(*begin_it != *end_it) {
            printf("0");
            return 0;
        }
        else {
            ++begin_it;
            --end_it;
        }
    }

    printf("1");

    return 0;
}