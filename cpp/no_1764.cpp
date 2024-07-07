#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_not_heard, num_not_saw;
    cin >> num_not_heard >> num_not_saw;

    unordered_set<string> not_heard_set, not_saw_set;

    for(int i = 0; i < num_not_heard; i++) {
        string not_heard;
        cin >> not_heard;
        not_heard_set.insert(not_heard);
    }

    for(int i = 0; i < num_not_saw; i++) {
        string not_saw;
        cin >> not_saw;
        not_saw_set.insert(not_saw);
    }

    set<string> not_heard_and_saw_set;

    if(num_not_heard < num_not_saw) {
        for(const string& not_heard: not_heard_set) {
            if(not_saw_set.find(not_heard) != not_saw_set.end()) {
                not_heard_and_saw_set.insert(not_heard);
            }
        }
    }
    else {
        for(const string& not_saw: not_saw_set) {
            if(not_heard_set.find(not_saw) != not_heard_set.end()) {
                not_heard_and_saw_set.insert(not_saw);
            }
        }
    }

    cout << not_heard_and_saw_set.size() << endl;
    for(const string& not_heard_and_saw: not_heard_and_saw_set) {
        cout << not_heard_and_saw << endl;
    }

    return 0;
}