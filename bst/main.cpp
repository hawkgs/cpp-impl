#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    public:
        Node *left;
        Node *right;
        int value;
        Node(int v);
};

Node::Node(int v) {
    value = v;
    left = NULL;
    right = NULL;
}

class BST {
    public:
        Node *root;
        BST();
        ~BST();
        void add(int value);
    private:
        void attachNode(Node *curr, Node *node);
        void clean(Node *curr);
};

BST::BST() {
    root = NULL;
}

BST::~BST() {
    this->clean(root);
}

void BST::add(int value) {
    Node *node = new Node(value);

    if (root) {
        this->attachNode(root, node);
    }
    else {
        root = node;
    }
}

void BST::attachNode(Node *curr, Node *node) {
    if (curr->value > node->value) {
        curr->left = node;
    }
    else if (node->value >= curr->value && !curr->right) {
        curr->right = node;
    }
    else {
        this->attachNode(curr->right, node);
    }
}

void BST::clean(Node *curr) {
    if (curr->left) {
        this->clean(curr->left);
    }
    if (curr->right) {
        this->clean(curr->right);
    }
    // cout << "deleting: " << curr << "; with value: " << curr->value << ";" << endl;
    delete curr;
}

void printBST(Node *node, int nodeVal, char *pos) {
    cout << pos << " " << nodeVal << ": " << node->value << endl;

    if (node->left) {
        printBST(node->left, node->value, (char*)"Left of");
    }
    if (node->right) {
        printBST(node->right, node->value, (char*)"Right of");
    }
}

int main() {
    BST bst;

    bst.add(3);
    bst.add(2);
    bst.add(4);
    bst.add(3);
    bst.add(5);
    bst.add(6);
    bst.add(7);

    printBST(bst.root, bst.root->value, (char*)"Root");

    cout << endl << "end" << endl;

    return 0;
}
