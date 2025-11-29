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

node* getIntersectionNode(node *headA, node *headB) {
    node *a = headA;
    node *b = headB;

    while (a!=NULL||b!=NULL){
        if (a==b)
            return a; 

        if (a!=NULL)
            a=a->next;
        else
            a=headB;

        if (b!=NULL)
            b=b->next;
        else
            b=headA;
    }

    return NULL; 
}

int main() {
    
    node* c1=createNode(6);
    node* c2=createNode(7);
    node* c3=createNode(8);
    c1->next=c2;
    c2->next=c3;

    node* a1=createNode(1);
    node* a2=createNode(2);
    node* a3=createNode(3);
    a1->next=a2;
    a2->next=a3;
    a3->next=c1;

    node* b1=createNode(4);
    node* b2=createNode(5);
    b1->next=b2;
    b2->next=c1;

    node* intersection = getIntersectionNode(a1, b1);

    if (intersection !=NULL)
        cout<<"Intersection at node with data: " <<intersection->data<<endl;
    else
        cout<<"No intersection found." <<endl;

    return 0;
}
