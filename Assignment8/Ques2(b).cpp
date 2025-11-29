#include <iostream>
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* add_node(Node* parent, int data) {
    if (parent == NULL) {
        Node* NewNode = new Node;
        NewNode->data = data;
        NewNode->left = NULL;
        NewNode->right = NULL;
        return NewNode;
    }
    if (data < parent->data) parent->left = add_node(parent->left, data);
    else if (data > parent->data) parent->right = add_node(parent->right, data);
    return parent;
}

Node* find_max(Node* parent) {
    if (parent == NULL || parent->right == NULL) return parent;
    return find_max(parent->right);
}

int main() {
    Node* root = NULL;
    root = add_node(root, 5);
    root = add_node(root, 6);
    root = add_node(root, 3);
    root = add_node(root, 7);
    root = add_node(root, 4);

    Node* maxNode = find_max(root);

    std::cout << "Maximum Element: ";
    if (maxNode) std::cout << maxNode->data << "\n"; 
    else std::cout << "Tree Empty\n";

    return 0;
}
