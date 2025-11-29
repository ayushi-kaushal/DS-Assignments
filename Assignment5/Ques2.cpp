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

int deleteAndCount(node*& head, int key) {
    int count = 0;

    while (head != NULL && head->data == key) {
        node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == key) {
            node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            count++;
        } else {
            current = current->next;
        }
    }

    return count;
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
    node* a4 = createNode(2);
    node* a5 = createNode(4);

    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;

    node* head = a1;

    int key = 2;

    cout << "Original list: ";
    display(head);

    int count = deleteAndCount(head, key);

    cout << "Number of occurrences of " << key << ": " << count << endl;
    cout << "List after deleting " << key << ": ";
    display(head);

    return 0;
}
