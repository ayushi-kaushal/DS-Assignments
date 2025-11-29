#include <iostream>
struct Node{
    int data;
    Node* next;
};

Node* head = NULL; 
Node* current = NULL;

void create_node(int x, Node* &head, Node* &current){
    Node* NewNode = new Node;
    NewNode->data = x;
    NewNode->next = NULL;

    if(head == NULL){
        head = NewNode;
        current = head;
        current->next = head; 
    } else {
        current->next = NewNode;
        current = current->next;
        current->next = head; 
    }
}

void display(Node* head){
    if(head == NULL){
        std::cout << "No nodes!\n";
        return;
    }
    Node* temp = head;
    do{
        std::cout << temp->data << "\t";
        temp = temp->next;
    } while(temp != head);
    std::cout << "\n";
}

void del_even_parity(Node* &head){
    if(head == NULL) return;

    Node* temp = head;
    Node* prev = NULL;

    do{
        Node* nextNode = temp->next;

        int x = temp->data;
        int parity = 0;
        while(x != 0){
            if(x & 1) parity++;
            x = x >> 1;
        }

        if(parity % 2 == 0){ 
            if(temp == head){
                if(head->next == head){ 
                    delete head;
                    head = NULL;
                    return;
                }
               
                Node* last = head;
                while(last->next != head) last = last->next;
                head = head->next;
                last->next = head;
                delete temp;
            } else {
                prev->next = temp->next;
                delete temp;
            }
        } else {
            prev = temp;
        }

        temp = nextNode;
    } while(head != NULL && temp != head);
}

int main() {
    create_node(3, head, current);
    create_node(4, head, current);
    create_node(16, head, current);

    std::cout << "list before:\t"; 
    display(head);
    del_even_parity(head);
    std::cout << "list after:\t"; 
    display(head);
}
