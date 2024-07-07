#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;

    int i = 0;
    int add_cnt = 0;

    try {
        i = stoi(str1);
        add_cnt = 3;
    }
    catch(exception& e1) {
        try {
            i = stoi(str2);
            add_cnt = 2;
        }
        catch(exception& e2) {
            try {
                i = stoi(str3);
                add_cnt = 1;
            }
            catch(exception& e3) {
                cerr << "No Changeable Number" << endl;
            }
        }
    }

    i += add_cnt;

    if(i % 3 == 0 && i % 5 == 0) {
        cout << "FizzBuzz" << endl;
    }
    else if(i % 3 == 0 && i % 5 != 0) {
        cout << "Fizz" << endl;
    }
    else if(i % 3 != 0 && i % 5 == 0) {
        cout << "Buzz" << endl;
    }
    else {
        cout << i << endl;
    }

    return 0;
}