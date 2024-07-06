#include <iostream>
#include <string>

using namespace std;

int main() {
    string str_n;
    cin >> str_n;

    int int_n = stoi(str_n);

    int result=1000000;
    for(int i = int_n; i >= 0; i--) {
        string digits = to_string(i);
        string temp_str_n;
        int temp_int_n = int_n;
        for(const char& digit: digits) {
            temp_int_n -= (digit - '0');
            temp_str_n += digit;
        }
        if(stoi(temp_str_n) == temp_int_n) {
            if(result > temp_int_n) {
                result = temp_int_n;
            }
        }
    }

    if(result == 1000000) {
        cout << 0 << endl;
    }
    else {
        cout << result << endl;
    }

    return 0;
}