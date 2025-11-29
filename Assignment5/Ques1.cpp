#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = nullptr;

void insert_at_begin() {
    int value;
    cout << "enter value\n";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insert_at_end() {
    int value;
    cout << "enter value\n";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insert_in_middle() {
    int value, afterValue;
    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Insert after which value? ";
    cin >> afterValue;

    Node* temp = head;
    while(temp != nullptr && temp->data != afterValue){
        temp = temp->next;
    }

    if(temp == nullptr){
        cout << "Value not found!\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_from_begin(){
    if(head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void delete_from_end(){
    if(head == nullptr) return;
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while(temp->next->next != nullptr) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void delete_specific_node(){
    int value;
    cout << "Enter value to delete: ";
    cin >> value;

    if(head == nullptr) return;
    if(head->data == value){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr && temp->next->data != value){
        temp = temp->next;
    }

    if(temp->next == nullptr){
        cout << "Value not found!\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

void node_from_head(){
    int value;
    cout << "Enter value to find position: ";
    cin >> value;

    Node* temp = head;
    int pos = 0;
    while(temp != nullptr){
        if(temp->data == value){
            cout << "Position from head: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value not found!\n";
}

void node_values(){
    Node* temp = head;
    if(temp == nullptr){
        cout << "List is empty.\n";
        return;
    }
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void menu(int x){
    switch(x){
        case 1: insert_at_begin(); break;
        case 2: insert_at_end(); break;
        case 3: insert_in_middle(); break;
        case 4: delete_from_begin(); break;
        case 5: delete_from_end(); break;
        case 6: delete_specific_node(); break;
        case 7: node_from_head(); break;
        case 8: node_values(); break;
        default: cout << "Invalid choice!\n";
    }
}

int main(){
    cout << "\tTo insert : \nat start press 1\nat end press 2\nafter specific value press 3\n\n \t To delete:\nfrom start press 4\nfrom end press 5\nspecific node press 6 \n\n\tTo know node position from the head press 7\n\tTo print all node values press 8\n\n\tTo exit press 9\n";

    int a;
    while(true){
        cin >> a;
        if(a == 9) break;
        menu(a);
    }
    return 0;
}
