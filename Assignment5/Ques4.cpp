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

node* reverseList(node* head) {
    node* prev = NULL;
    node* current = head;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

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
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;

    cout << "Original list: ";
    display(a1);

    node* reversedHead = reverseList(a1);

    cout << "Reversed list: ";
    display(reversedHead);

    return 0;
}
