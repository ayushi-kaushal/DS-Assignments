#include <iostream>
using namespace std;

string queue[100];
int front=-1, rear=-1;
int n;

int isEmpty() {
    if (front==-1 && rear==-1) return 1;
    else return 0;
}

int isFull() {
    if ((rear+1)%100==front) return 1;
    else return 0;
}

void enqueue(string x) {
    if (isFull()==0) {
        if (isEmpty()==1) {
            front=rear= 0;
        } else {
            rear=(rear+1)%100;
        }
        queue[rear]=x;
    }
}

string dequeue() {
    if (isEmpty()==1) return "";
    string temp=queue[front];
    if (front==rear) {
        front=rear=-1;
    } else {
        front=(front + 1) % 100;
    }
    return temp;
}

void binary() {
    enqueue("1");
    for (int i=1; i<=n; i++) {
        string current=dequeue();
        cout<<current<<"\n";   
        enqueue(current+"0");
        enqueue(current+"1");
    }
}

int main() {
    cout<<"Enter n: ";
    cin>>n;
    binary();
    return 0;
}
