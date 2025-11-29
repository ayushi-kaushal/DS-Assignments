#include <iostream>
using namespace std;

int queue[50];
int front_queue=-1;
int rear_queue=-1;
int size_queue=0;
int stack[50];
int top_stack=-1;
int output_queue[50];
int front_output=-1;
int rear_output=-1;
int size_output=0;


void enqueue(int x) {
    if (front_queue==-1 && rear_queue==-1) front_queue=rear_queue=0;
    else rear_queue++;
    queue[rear_queue]=x;
    size_queue++;
}

int dequeue() {
    if (front_queue==-1) return -1;
    int temp=queue[front_queue];
    if (front_queue==rear_queue) front_queue=rear_queue=-1;
    else front_queue++;
    size_queue--;
    return temp;
}

void enqueue_output(int x) {
    if (front_output==-1 && rear_output==-1) front_output=rear_output=0;
    else rear_output++;
    output_queue[rear_output]=x;
    size_output++;
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

bool check_queue(int n) {
    int expected = 1;
    while (size_queue > 0) {
        int curr = dequeue();
        
        while (stack_peek() == expected) {
            int val = pop();
            enqueue_output(val);
            expected++;
        }
        if (curr == expected) {
            enqueue_output(curr);
            expected++;
        } else {
            push(curr);
        }
    }
    while (stack_peek() == expected) {
        int val = pop();
        enqueue_output(val);
        expected++;
    }
    return expected == n + 1;
}


void display_output() {
    if (size_output == 0) {
        cout << "Output queue is empty\n";
        return;
    }
    for (int i = 0; i < size_output; i++) {
        if (i > 0) cout << ", ";
        cout << output_queue[i];
    }
    cout << "\n";
}

int main() {
    int arr[] = {5,1,2,3,4};
    int n = 5;

    for (int i=0; i<n; i++) enqueue(arr[i]);

    if (check_queue(n)) {
        cout << "Yes\n";
        cout << "Sorted output queue: ";
        display_output();
    } else {
        cout << "No\n";
    }

    return 0;
}
