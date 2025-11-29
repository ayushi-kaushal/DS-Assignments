#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node* createNode(int value) {
    node* temp=new node;
    temp->data=value;
    temp->next=NULL;
    return temp;
}

node* rotateLeft(node* head, int k) {
    if (head==NULL||head->next==NULL||k==0)
        return head;

    
    node* tail=head;
    int n=1;
    while (tail->next!=NULL) {
        tail=tail->next;
        n++;
    }

    
    tail->next=head;


    k=k%n;
    if (k==0) {
        tail->next =NULL;
        return head;
    }

    node* newTail=head;
    for (int i=1; i<k; i++)
        newTail=newTail->next;

    node* newHead=newTail->next;

    
    newTail->next=NULL;

    return newHead;
}


void printList(node* head) {
    while (head != NULL) {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main() {
    
    node* a1=createNode(1);
    node* a2=createNode(2);
    node* a3=createNode(3);
    node* a4=createNode(4);
    node* a5=createNode(5);

    
    a1->next=a2;
    a2->next=a3;
    a3->next=a4;
    a4->next=a5;

    int k = 2;
    node* newHead=rotateLeft(a1,k);

    printList(newHead);

    return 0;
}
