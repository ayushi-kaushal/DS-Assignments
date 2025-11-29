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

Node* find_min(Node* parent) {
    if (parent == NULL || parent->left == NULL) return parent;
    return find_min(parent->left);
}

Node* successor(Node* parent, int data) {
    Node* succ = NULL;
    Node* current = parent;
    while (current != NULL) {
        if (data < current->data) {
            succ = current;
            current = current->left;
        } 
        else if (data > current->data) {
            current = current->right;
        } 
        else {
            if (current->right != NULL)
                succ = find_min(current->right);
            break;
        }
    }
    return succ;
}

int main() {
    Node* root = NULL;
    root = add_node(root, 20);
    root = add_node(root, 8);
    root = add_node(root, 22);
    root = add_node(root, 4);
    root = add_node(root, 12);
    root = add_node(root, 10);
    root = add_node(root, 14);

    int key = 10;
    Node* succ = successor(root, key);

    std::cout << "In-order Successor of " << key << ": ";
    if (succ) std::cout << succ->data << "\n";
    else std::cout << "No Successor\n";

    return 0;
}
