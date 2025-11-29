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

void removeLoop(node* head) {
    if (head==NULL||head->next==NULL)
        return;

    node* slow=head;
    node* fast=head;

    
    bool loopExists=false;
    while (fast!=NULL&&fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;

        if (slow==fast) {
            loopExists=true;
            break;
        }
    }

    if (loopExists==false)
       { return;}

    
    slow=head;
    node* prev=fast; 

    while (slow!=fast) {
        slow=slow->next;
        prev=fast;
        fast=fast->next;
    }
    prev->next=NULL;
}


void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    
    node* a1=createNode(1);
    node* a2=createNode(2);
    node* a3=createNode(3);
    node* a4=createNode(4);
    node* a5=createNode(5);

    
    a1->next=a2;
    a2->next=a3;
    a3->next=a4;
    a4->next=a5;

    
    a5->next=a3;

    removeLoop(a1);
    printList(a1); 
    
}
