#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Node {
public:
    char key;
    bool is_terminal;
    map<char, Node*> children;

    explicit Node(const char& key = 0, const bool& is_end = false) : key(key), is_terminal(is_end) { }
};

class Trie {
private:
    Node* head = nullptr;

    void clearMemory(const Node* node) {
        for (const pair<const char, Node*>& child : node->children) {
            clearMemory(child.second);
        }
        delete node;
    }

public:
    Trie() {
        head = new Node();
    }

    ~Trie() {
        clearMemory(head);
    }

    void insert(const string& key) {
        Node* curr = head;
        for (char ch : key) {
            if (!curr->children.contains(ch)) {
                curr->children[ch] = new Node(ch);
            }
            curr = curr->children[ch];
        }
        curr->is_terminal = true;
    }

    [[nodiscard]] bool is_duplicated(const string& key) const {
        Node* curr = head;
        for (char ch : key) {
            if (!curr->children.contains(ch)) {
                return false;
            }
            curr = curr->children[ch];
            if (curr->is_terminal) {
                return true;
            }
        }
        return !(curr->children.empty());
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_cases;
    cin >> num_cases;

    for(int i = 0; i < num_cases; i++) {
        int n;
        cin >> n;
        Trie trie;
        bool has_duplicate = false;
        vector<string> phone_numbers(n);

        for(int j = 0; j < n; j++) {
            cin >> phone_numbers[j];
        }

        for(int j = 0; j < n; j++) {
            if(trie.is_duplicated(phone_numbers[j])) {
                has_duplicate = true;
                break;
            }
            trie.insert(phone_numbers[j]);
        }

        cout << (has_duplicate ? "NO" : "YES") << endl;
    }

    return 0;
}
