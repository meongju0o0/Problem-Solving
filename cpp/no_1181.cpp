#include <iostream>
#include <string>
#include <set>

using namespace std;

struct cmp {
    bool operator() (const string& a, const string& b) const {
        if (a.size() == b.size())
            return a < b;
        else
            return a.size() < b.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<string, cmp> words;

    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.insert(word);
    }

    for(const string& word: words) {
        cout << word << endl;
    }

    return 0;
}