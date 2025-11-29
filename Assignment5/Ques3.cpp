#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* createNode(int value) {
    node* temp=new node;
    temp->data=value;
    temp->next=NULL;
    return temp;
}


node* findMiddle(node* head) {
    if (head==NULL)
        return NULL;

    node* slow=head;
    node* fast=head;

    
    while (fast!=NULL&&fast->next !=NULL) {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

void printList(node* head) {
    while (head!=NULL) {
        cout<<head->data << " ";
        head=head->next;
    }
    cout<<endl;
}

int main() {
    
    node* a1 = createNode(1);
    node* a2 = createNode(2);
    node* a3 = createNode(3);
    node* a4 = createNode(4);
    node* a5 = createNode(5);

    
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;

    printList(a1);

    node* middle = findMiddle(a1);
    if (middle != NULL)
        cout<<"Middle node data: "<< middle->data<<endl;

    return 0;
}
