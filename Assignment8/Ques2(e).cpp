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

Node* predecessor(Node* parent, int data) {
    Node* pred = NULL;
    Node* current = parent;
    while (current != NULL) {
        if (data > current->data) {
            pred = current;
            current = current->right;
        } 
        else if (data < current->data) {
            current = current->left;
        } 
        else {
            if (current->left != NULL)
                pred = find_max(current->left);
            break;
        }
    }
    return pred;
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

    int key = 14;
    Node* pred = predecessor(root, key);

    std::cout << "In-order Predecessor of " << key << ": ";
    if (pred) std::cout << pred->data << "\n";
    else std::cout << "No Predecessor\n";

    return 0;
}
