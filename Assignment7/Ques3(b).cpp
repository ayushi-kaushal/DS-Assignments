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

Node* find_min(Node* node) {
    if (node == NULL || node->left == NULL) return node;
    return find_min(node->left);
}

Node* delete_node(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = delete_node(root->left, key);
    else if (key > root->data)
        root->right = delete_node(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
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

    std::cout << "In-order before deletion: ";
    inorder(root);
    std::cout << "\n";

    int key = 8;
    root = delete_node(root, key);

    std::cout << "In-order after deleting " << key << ": ";
    inorder(root);
    std::cout << "\n";

    return 0;
}
