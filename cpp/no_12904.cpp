#include <iostream>
#include <string>

using namespace std;

void reverse_string(string& str) {
    string temp_str = str;
    str = "";
    while(!temp_str.empty()) {
        str += temp_str.back();
        temp_str.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    while(s.size() != t.size()) {
        if(t.back() == 'A') {
            t.pop_back();
        }
        else if(t.back() == 'B') {
            t.pop_back();
            reverse_string(t);
        }
    }

    cout << (t == s) << endl;

    return 0;
}
