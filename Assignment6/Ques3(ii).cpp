#include <iostream>
struct Node{
    int data;
    Node* next;
};

Node* head=NULL; 
Node* current= head;

 void create_node(int x,Node* &head,Node* &current){
     Node* NewNode=new Node; 
     NewNode->data=x;
     NewNode->next=NULL;
     
     if(head==NULL){
         head=NewNode;
    current=head; } else 
     {current->next=NewNode; 
        current=current->next;  }
      
      }

int nodeCount(Node* head){ Node* temp=head;
int count=0;
if (head == nullptr) return 0;

do {  count++;
    temp=temp->next;
    } while(temp!=head);
    return count;
    }
    
int main() { create_node(3,head,current);
create_node(4,head,current);
create_node(5,head,current);
current->next=head;
std::cout<<nodeCount(head);
}
