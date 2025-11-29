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

Node* search_recursive(Node* parent, int key) {
    if (parent == NULL || parent->data == key) return parent;
    if (key < parent->data) return search_recursive(parent->left, key);
    return search_recursive(parent->right, key);
}

Node* search_nonrecursive(Node* parent, int key) {
    Node* temp = parent;
    while (temp != NULL) {
        if (temp->data == key) return temp;
        if (key < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    return NULL;
}

int main() {
    Node* root = NULL;
    root = add_node(root, 5);
    root = add_node(root, 6);
    root = add_node(root, 3);
    root = add_node(root, 4);
    root = add_node(root, 2);

    int key = 4;
    Node* r1 = search_recursive(root, key);
    Node* r2 = search_nonrecursive(root, key);

    std::cout << "Recursive Search: ";
    if (r1) std::cout << "Found " << r1->data << "\n"; 
    else std::cout << "Not Found\n";

    std::cout << "Non-Recursive Search: ";
    if (r2) std::cout << "Found " << r2->data << "\n"; 
    else std::cout << "Not Found\n";

    return 0;
}
