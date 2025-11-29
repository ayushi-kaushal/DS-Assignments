#include <iostream>
using namespace std;
int stacksize=50;
int stack1[50];
int stackmin[50];
int top_stack = -1, top_stackmin=-1;

int isEmpty(int top){if (top==-1) { return 1;}else return 0;}

int isFull(int top){if(top==stacksize-1){ return 1;} else return 0;}

void push(int x){  
    if(isFull(top_stack)!=1)
    {top_stack=top_stack+1;
    stack1[top_stack]=x;
if(isEmpty(top_stackmin)==1 || x<=stackmin[top_stackmin])
    {top_stackmin=top_stackmin+1;
    stackmin[top_stackmin]=x;}}}
    


int pop(){ if (isEmpty(top_stack)==1){ cout<<"Error,underflow\n";  return -1;} 
int topVal=stack1[top_stack];

   top_stack--;
        if(topVal==stackmin[top_stackmin]){
   top_stackmin--;
return topVal;} return 1;}

int getMin(){if (isEmpty(top_stackmin)==1){cout<<"No elements found\n"; return -1;
   }
   return stackmin[top_stackmin] ;}
    int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int A[50];
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++) {
        cin>>A[i];
        push(A[i]);}
    int a=getMin();
    cout<<"Min is "<<a<<"\n";}
     
   
