#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    int n;
    cin >> n;

    list<char> mylist;
    for(const char& ch: str) {
        mylist.push_back(ch);
    }

    auto it = mylist.end();
    for(int i = 0; i < n; i++) {
        char command;
        cin >> command;

        if(command == 'L') {
            if(it != mylist.begin()) {
                --it;
            }
        }
        else if(command == 'D') {
            if(it != mylist.end()) {
                ++it;
            }
        }
        else if(command == 'B') {
            if(it != mylist.begin()) {
                it = mylist.erase(--it);
            }
        }
        else if(command == 'P') {
            char item;
            cin >> item;
            mylist.insert(it, item);
        }
    }

    for(const char& ch: mylist) {
        cout << ch;
    }

    return 0;
}