#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node {
    string item;
    Node* left_child = nullptr;
    Node* right_child = nullptr;
};

class Tree {
private:
    Node* root;

    void _print_preorder(const Node* cur_node) {
        if(cur_node == nullptr) {
            return;
        }
        else {
            printf("%s", (cur_node->item).c_str());
            _print_preorder(cur_node->left_child);
            _print_preorder(cur_node->right_child);
        }
    }

    void _print_inorder(const Node* cur_node) {
        if(cur_node == nullptr) {
            return;
        }
        else {
            _print_inorder(cur_node->left_child);
            printf("%s", (cur_node->item).c_str());
            _print_inorder(cur_node->right_child);
        }
    }

    void _print_postorder(const Node* cur_node) {
        if(cur_node == nullptr) {
            return;
        }
        else {
            _print_postorder(cur_node->left_child);
            _print_postorder(cur_node->right_child);
            printf("%s", (cur_node->item).c_str());
        }
    }

    void _delete_nodes(const Node* cur_node) {
        if(cur_node->left_child == nullptr || cur_node->right_child == nullptr) {
            delete cur_node;
        }
        else {
            _delete_nodes(cur_node->left_child);
            _delete_nodes(cur_node->right_child);
        }
    }

public:
    Tree() {
        root = nullptr;
    };

    ~Tree() {
        _delete_nodes(root);
    }

    void add_node(const string& root_item, const string& left_child_item, const string& right_child_item) {
        Node* cur_node;

        if(root == nullptr) {
            root = new Node();
            root->item = root_item;
            cur_node = root;
        }
        else {
            queue<Node*> candidates;
            candidates.push(root);

            while(!candidates.empty()) {
                cur_node = candidates.front();
                candidates.pop();
                if(cur_node->item == root_item) {
                    break;
                }
                else {
                    if(cur_node->left_child != nullptr) {
                        candidates.push(cur_node->left_child);
                    }
                    if(cur_node->right_child != nullptr) {
                        candidates.push(cur_node->right_child);
                    }
                }
            }
        }

        if(left_child_item != ".") {
            cur_node->left_child = new Node();
            cur_node->left_child->item = left_child_item;
        }
        if(right_child_item != ".") {
            cur_node->right_child = new Node();
            cur_node->right_child->item = right_child_item;
        }
    }

    void print_preorder() {
        _print_preorder(root);
        printf("\n");
    }

    void print_inorder() {
        _print_inorder(root);
        printf("\n");
    }

    void print_postorder() {
        _print_postorder(root);
        printf("\n");
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Tree tree;
    for(int i = 0; i < n; i++) {
        string root, left_child, right_child;
        cin >> root >> left_child >> right_child;
        tree.add_node(root, left_child, right_child);
    }

    tree.print_preorder();
    tree.print_inorder();
    tree.print_postorder();

    return 0;
}