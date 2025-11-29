#include <iostream>
using namespace std;

int queue[50], front_queue=-1, rear_queue=-1, size_queue=0;
int stack[50], top_stack=-1;

void enqueue(int x) {
    if (front_queue==-1 && rear_queue==-1) front_queue=rear_queue=0;
    else rear_queue++;
    queue[rear_queue]=x;
    size_queue++;
}

int dequeue(){
    if (front_queue==-1) return -1;
    int temp=queue[front_queue];
    if (front_queue==rear_queue) front_queue=rear_queue=-1;
    else front_queue++;
    size_queue--;
    return temp;
}

void push(int x) {
    top_stack++;
    stack[top_stack]=x;
}

int pop() {
    if (top_stack==-1) return -1;
    int temp=stack[top_stack];
    top_stack--;
    return temp;
}

int stack_peek() {
    if (top_stack==-1) return -1;
    return stack[top_stack];
}

int student_count(int n) {
    int rotations=0;
    while (size_queue>0 && rotations<size_queue) {
        int student=dequeue();
        if (student==stack_peek()){
            pop();           
            rotations=0;   
        } else{
            enqueue(student); 
            rotations++;
        }
    }
    return size_queue; 
}

int main(){
    int students[] = {1,1,0,0};
    int sandwiches[] = {0,1,0,1};
    int n = 4;

   
    for (int i=0;i<n;i++) enqueue(students[i]);
    for (int i=n-1;i>=0;i--) push(sandwiches[i]); 
    int unable=student_count(n);
    cout<<"Number of students unable to eat lunch: " << unable<<"\n";
    return 0;
}
