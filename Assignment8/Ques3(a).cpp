
#include <iostream>
struct Node{
    int data;
    Node* left;
    Node* right;
};  

Node* add_node(Node* parent,int data){
  Node* NewNode= new Node;
    
    if(parent==NULL){
        NewNode->data=data;
        NewNode->left=NULL;
        NewNode->right=NULL;
          return NewNode;
    }
    
    if(data<parent->data)
    {  parent->left=add_node(parent->left,data);}
    if(data>parent->data)
     {  parent->right=add_node(parent->right,data);}
    return parent;

}


int main() {
   Node* Node=NULL;
Node= add_node(Node,5);
Node= add_node(Node,6);
Node= add_node(Node,3);

    std::cout<<"Root:"<<Node->data<<std::endl;
    std::cout<<"Left:"<<Node->left->data<<std::endl;
    std::cout<<"Right:"<<Node->right->data<<std::endl;
    return 0;
}
