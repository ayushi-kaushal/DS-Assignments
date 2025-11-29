#include <iostream>
struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL; 
Node* tail = head;

void create_node(int x, Node* &head, Node* &tail){
    Node* NewNode = new Node; 
    NewNode->data = x;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    if(head == NULL){
        head = NewNode;
        tail = head; 
    } else {
        tail->next = NewNode; 
        NewNode->prev = tail;
        tail = tail->next;  
    }
}

void display(Node* head){
    Node* temp = head;
    if (head == NULL) {
        std::cout << "No nodes!\n";
    } else {  
        while(temp != NULL) {
            std::cout << temp->data << "\t";
            temp = temp->next;
        }
        std::cout << "\n";
    }
}

void del_even_parity(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        Node* nextNode = temp->next;

        int x = temp->data;
        int parity = 0;
        while(x != 0){
            if(x & 1)
                parity++;
            x = x >> 1;
        }

        if(parity%2==0){
            if(temp->prev!=NULL)
                temp->prev->next=temp->next;
            else
                head=temp->next; 
            if(temp->next!=NULL)
                temp->next->prev=temp->prev;
            delete temp;
        }

        temp = nextNode;
    }
}

int main() {
    create_node(3,head,tail);
    create_node(4,head,tail);
    create_node(16,head,tail);
    std::cout<<"list before:\t"; 
    display(head);
    del_even_parity(head);
     std::cout<<"list after:\t"; 
    display(head);
}
