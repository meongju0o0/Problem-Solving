#include <iostream>
#include <string>
#include <set>

using namespace std;

struct cmp {
    bool operator() (const string& a, const string& b) const {
        return a > b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<string, cmp> employees;
    for(int i = 0; i < n; i++) {
        string name, command;
        cin >> name >> command;
        if(command == "enter") {
            employees.insert(name);
        }
        else if(command == "leave") {
            employees.erase(name);
        }
    }

    for(const string& name: employees) {
        printf("%s\n", name.c_str());
    }

    return 0;
}