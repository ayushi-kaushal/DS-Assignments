#include <iostream>
using namespace std;
int stacksize=50;
int stack1[50];
int top = -1;;

int isEmpty(){if (top==-1) { return 1;}else return 0;}

int isFull(){if(top==stacksize-1){ return 1;} else return 0;}

void push(int input){ 
    if(isFull()!=1)
    {top=top+1;
    stack1[top]=input;}
}

int pop(){ if (isEmpty()!=1){
    int input=stack1[top];
    top=top-1;
    return input;
} else return -1;
}
void nearestSmallerToLeft(int A[],int n)
{ int G[50];   top = -1;
        for(int i=0;i<n;i++){
            while(isEmpty()!=1 &&stack1[top]>=A[i]){ pop();}
         if(isEmpty()==1){G[i]=-1;}else {G[i]=stack1[top];}
     push(A[i]); } for(int i=0;i<n;i++){
        cout<<G[i]<<" ";
    } }
    
    
    
    int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int A[50];
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++) {
        cin>>A[i];
    }
    nearestSmallerToLeft(A,n);
    } 
   
