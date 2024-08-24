#include <iostream>

using namespace std;

struct Node {
    int data = 0;
    Node* left_child = nullptr;
    Node* right_child = nullptr;
};

class Tree {
private:
    Node* root;

    void delete_nodes(Node* cur_node) {
        if(cur_node == nullptr) {
            return;
        }
        else {
            delete_nodes(cur_node->left_child);
            delete_nodes(cur_node->right_child);
            delete cur_node;
            return;
        }
    }

public:
    Tree() {
        this->root = nullptr;
    }

    ~Tree() {
        delete_nodes(root);
    }

    void add_Node(int data) {
        if(root == nullptr) {
            root = new Node;
            root->data = data;
        }
        else {
            Node* cur_node = root;
            while(true) {
                if(cur_node->data > data) {
                    if(cur_node->left_child == nullptr) {
                        cur_node->left_child = new Node;
                        cur_node->left_child->data = data;
                        break;
                    }
                    else {
                        cur_node = cur_node->left_child;
                    }
                }
                else if(cur_node->data < data) {
                    if(cur_node->right_child == nullptr) {
                        cur_node->right_child = new Node;
                        cur_node->right_child->data = data;
                        break;
                    }
                    else {
                        cur_node = cur_node->right_child;
                    }
                }
                else {
                    cerr << "Duplicated Data" << endl;
                    break;
                }
            }
        }
    }

    Node* get_root() {
        return root;
    }

    void print_postorder(Node* cur_node) {
        if(cur_node == nullptr) {
            return;
        }
        else {
            print_postorder(cur_node->left_child);
            print_postorder(cur_node->right_child);
            cout << cur_node->data << endl;
            return;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Tree tree = Tree();

    int data;
    while(cin >> data) {
        tree.add_Node(data);
    }

    tree.print_postorder(tree.get_root());

    return 0;
}