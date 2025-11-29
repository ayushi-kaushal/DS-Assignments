#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = nullptr;

void insert_at_begin() {
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;

    if(head == nullptr){
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* last = head;
    while(last->next != head) last = last->next;

    newNode->next = head;
    last->next = newNode;
    head = newNode;
}

void insert_at_end() {
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;

    if(head == nullptr){
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* last = head;
    while(last->next != head) last = last->next;

    last->next = newNode;
    newNode->next = head;
}

void insert_after_value() {
    if(head == nullptr){
        cout << "List is empty!\n";
        return;
    }

    int value, afterValue;
    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Insert after which value? ";
    cin >> afterValue;

    Node* temp = head;
    do {
        if(temp->data == afterValue) break;
        temp = temp->next;
    } while(temp != head);

    if(temp->data != afterValue){
        cout << "Value not found!\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insert_before_value() {
    if(head == nullptr){
        cout << "List is empty!\n";
        return;
    }

    int value, beforeValue;
    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Insert before which value? ";
    cin >> beforeValue;

    Node* newNode = new Node;
    newNode->data = value;

    if(head->data == beforeValue){
        Node* last = head;
        while(last->next != head) last = last->next;
        newNode->next = head;
        last->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != head && temp->next->data != beforeValue) temp = temp->next;

    if(temp->next->data != beforeValue){
        cout << "Value not found!\n";
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_specific_node() {
    if(head == nullptr){
        cout << "List is empty!\n";
        return;
    }

    int value;
    cout << "Enter value to delete: ";
    cin >> value;

    Node* temp = head;
    Node* prev = nullptr;

    if(head->data == value){
        if(head->next == head){
            delete head;
            head = nullptr;
            return;
        }
        Node* last = head;
        while(last->next != head) last = last->next;
        Node* delNode = head;
        head = head->next;
        last->next = head;
        delete delNode;
        return;
    }

    prev = head;
    temp = head->next;
    while(temp != head && temp->data != value){
        prev = temp;
        temp = temp->next;
    }

    if(temp == head){
        cout << "Value not found!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
}

void search_node() {
    if(head == nullptr){
        cout << "List is empty.\n";
        return;
    }

    int value;
    cout << "Enter value to search: ";
    cin >> value;

    Node* temp = head;
    int pos = 0;
    do {
        if(temp->data == value){
            cout << "Value found at position " << pos << " from head.\n";
            return;
        }
        temp = temp->next;
        pos++;
    } while(temp != head);

    cout << "Value not found!\n";
}

void display_list() {
    if(head == nullptr){
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while(temp != head);
    cout << "(head)\n";
}

void menu(int choice){
    switch(choice){
        case 1: insert_at_begin(); break;
        case 2: insert_at_end(); break;
        case 3: insert_after_value(); break;
        case 4: insert_before_value(); break;
        case 5: delete_specific_node(); break;
        case 6: search_node(); break;
        case 7: display_list(); break;
        default: cout << "Invalid choice!\n";
    }
}

int main(){
    cout << "Circular Singly Linked List Operations Menu\n";
    cout << "1: Insert at beginning\n2: Insert at end\n3: Insert after value\n";
    cout << "4: Insert before value\n5: Delete a specific node\n6: Search a node\n7: Display list\n8: Exit\n";

    int choice;
    while(true){ cout<<"Press your choice ";
        cin >> choice;
        if(choice == 8) break;
        menu(choice);
    }

    return 0;
}
