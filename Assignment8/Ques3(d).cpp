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

int min_depth(Node* root) {
    if (root == NULL) return -1;
    if (root->left == NULL && root->right == NULL) return 0;

    int left_depth = min_depth(root->left);
    int right_depth = min_depth(root->right);
    int depth;

    if (root->left == NULL)
        depth = right_depth + 1;
    else if (root->right == NULL)
        depth = left_depth + 1;
    else if (left_depth < right_depth)
        depth = left_depth + 1;
    else
        depth = right_depth + 1;

    return depth;
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

    std::cout << "Minimum Depth (in edges): " << min_depth(root) << "\n";
    return 0;
}
