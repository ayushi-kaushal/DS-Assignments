#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* createNode(int data) {
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

node* reverseK(node* head, int k) {
    node* current = head;
    node* prev = NULL;
    node* next = NULL;
    int count = 0;

    node* temp = head;
    int nodeCount = 0;
    while (temp != NULL && nodeCount < k) {
        temp = temp->next;
        nodeCount++;
    }
    if (nodeCount < k)
        return head;

    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    head->next = reverseK(current, k);

    return prev;
}

void display(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    node* a1 = createNode(1);
    node* a2 = createNode(2);
    node* a3 = createNode(3);
    node* a4 = createNode(4);
    node* a5 = createNode(5);
    node* a6 = createNode(6);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    a5->next = a6;

    int k = 3;

    cout << "Original list: ";
    display(a1);

    node* newHead = reverseK(a1, k);

    cout << "Reversed in groups of " << k << ": ";
    display(newHead);

    return 0;
}
