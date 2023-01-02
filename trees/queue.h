#include <iostream>

#ifndef queue_h
#define queue_h
using namespace std;

class Node{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue{
    private:
    int size;
    int front;
    int rear;
    Node **Q;

    public:
    Queue();
    Queue(int s);
    void enqueue(Node * x);
    Node * dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

Queue::Queue(){
    size = 10;
    front = rear = -1;
    Q=new Node*[size];
}

Queue::Queue(int size){
    this->size = size;
    front = rear = 0;
    Q=new Node*[size];
}

bool Queue::isEmpty(){
    if(front == rear){
        return true;
    }
    return false;
}

bool Queue::isFull(){
    if((rear+1)%size==front){
        return true;
    }
    return false;
}

void Queue::enqueue(Node *x){
    if(isFull()){
        cout<<"Queue is Full"<<endl;
    }else{
        rear=(rear+1)%size;
        Q[rear]=x;
    }
}

Node* Queue::dequeue(){
    Node* x=NULL;
    if(isEmpty()){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        front=(front+1)%size;
        x=Q[front];
    }
    return x;
}

void Queue::display(){
    for(int i=front+1;i<=rear;i++){
        cout<<Q[i];
        if(i<rear){
            cout<<" <- ";
        }
    }
    cout<<endl;
}

#endif