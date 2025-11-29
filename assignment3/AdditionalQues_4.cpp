
#include <iostream>
int Temperatures[50]; 
int answer[50]; 
int total_days;
void input();
int stack[50];
int top=-1;
void push(int data){
    if(top==total_days-1){
        std::cout<<"Overflow\n";
    }else {top=top+1;
        stack[top]=data;
    }
}
int pop(){ if(top==-1)
{
    std::cout<<"Underflow\n";
    return -1;
    } else { int value=stack[top];
        top=top-1;
        return value;
    }
    
}

int main() {
   
    input();
    for(int i=0;i<total_days;i++)
    {
        while(top!=-1 && Temperatures[stack[top]]<Temperatures[i])
      
     {   int prevIndex=pop();
     answer[prevIndex]=i-prevIndex;
     } push(i);
 
} for(int i=0;i<total_days;i++) 
{std::cout<<"for day "<<i+1<<" we waited "<<answer[i]<<" day/days \n";}
}

void input(){ 

std::cout<<"Enter number of days.\n";
std::cin>>total_days;

    for (int i=0;i<total_days;i++)
    {
        std::cout<<"Enter temperature for day "<<i+1<<": \n";
    std::cin>>Temperatures[i];}
    
}
