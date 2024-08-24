#include <iostream>
#include <string>
#include <tuple>
#include <set>

using namespace std;

struct cmp {
    bool operator() (const tuple<int, int, string>& a, const tuple<int, int, string>& b) const {
        if(get<1>(a) != get<1>(b)) {
            return get<1>(a) < get<1>(b);
        }
        else {
            return get<0>(a) < get<0>(b);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_records;
    cin >> num_records;

    set<tuple<int, int, string>, cmp> members;
    for(int idx = 0; idx < num_records; idx++) {
        int age;
        string name;
        cin >> age >> name;
        members.emplace(idx, age, name);
    }

    for(const tuple<int, int, string>& member: members) {
        printf("%d %s\n", get<1>(member), get<2>(member).c_str());
    }

    return 0;
}