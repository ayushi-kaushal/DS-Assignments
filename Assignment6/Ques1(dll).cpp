#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void insert_at_begin() {
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if(head != nullptr) head->prev = newNode;
    head = newNode;
}

void insert_at_end() {
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if(head == nullptr){
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
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
    while(temp != nullptr && temp->data != afterValue) temp = temp->next;

    if(temp == nullptr){
        cout << "Value not found!\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != nullptr) temp->next->prev = newNode;
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

    Node* temp = head;
    while(temp != nullptr && temp->data != beforeValue) temp = temp->next;

    if(temp == nullptr){
        cout << "Value not found!\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp;
    newNode->prev = temp->prev;

    if(temp->prev != nullptr) temp->prev->next = newNode;
    else head = newNode;

    temp->prev = newNode;
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
    while(temp != nullptr && temp->data != value) temp = temp->next;

    if(temp == nullptr){
        cout << "Value not found!\n";
        return;
    }

    if(temp->prev != nullptr) temp->prev->next = temp->next;
    else head = temp->next;

    if(temp->next != nullptr) temp->next->prev = temp->prev;

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
    while(temp != nullptr){
        if(temp->data == value){
            cout << "Value found at position " << pos << " from head.\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value not found!\n";
}

void display_list() {
    if(head == nullptr){
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
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
    cout << "Doubly Linked List Operations Menu\n";
    cout << "1: Insert at beginning\n2: Insert at end\n3: Insert after value\n";
    cout << "4: Insert before value\n5: Delete a specific node\n6: Search a node\n7: Display list\n8: Exit\n";

    int choice;
    while(true){cout<<"Press your choice: ";
        cin >> choice;
        if(choice == 8) break;
        menu(choice);
    }

    return 0;
}
