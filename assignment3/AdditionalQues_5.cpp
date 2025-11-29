#include <iostream>
using namespace std;
int stacksize=50;
int stack1[50];
int top=-1;
int Array[50];
int Array_Sorted[50];
int ArraySize=0;
int Array_B[50];

int isEmpty(){if (top==-1) {cout<<"Stack underflow\n"; return 1;}else return 0;}

int isFull(){if(top==stacksize-1){cout<<"Stack overflow\n"; return 1;} else return 0;}

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
void Sorting_A(int Array[],int n){                  //n is array size.
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++)
        {if(Array[j]>Array[j+1]){
            int temp=Array[j]; Array[j]=Array[j+1]; Array[j+1]=temp;}
        }
        }
    }
    
    int main(){ cout<<"Enter number of elements in Array\n";
    cin>>ArraySize;
    cout<<"Enter elements of the Array\n";
    for(int i=0;i<ArraySize;i++){cin>>Array[i];
        Array_Sorted[i]=Array[i];}
        Sorting_A(Array_Sorted,ArraySize);
        int j=0;
        for(int i=0;i<ArraySize;i++)
        {push(Array[i]); 
       while (top != -1 && stack1[top] == Array_Sorted[j]) {
        Array_B[j] = pop();
        j++; }}
         for (int i=0;i<j;i++) {
        cout << Array_B[i] << " ";
    }
    } 
   
