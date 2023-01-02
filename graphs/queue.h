#include <iostream>

#ifndef queue_h
#define queue_h
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
class Queue{
    private:
    Node *front;
    Node *rear;

    public:
    Queue(){
        front=rear=NULL;
    }
    void enqueue(int x);
    int dequeue();
    void display();
    bool isFull();
    bool isEmpty();
};

bool Queue::isFull(){
    Node *t=new Node;
    if(t){
        delete t;
        return false;
    }
    delete t;
    return true;
}

bool Queue::isEmpty(){
    if(!front){
        return true;
    }
    return false;
}

void Queue::enqueue(int x){
    Node *t=new Node;
    if(isFull()){
        cout<<"Queue Overflow"<<endl;
    }else{
        t->data =x;
        t->next = NULL;
        if(front==NULL){
            front = rear = t;
        }
        else{
            rear->next = t;
            rear =t;
        }
    }
}

int Queue::dequeue(){
    int x=-1;
    if(isEmpty()){
        cout<<"Queue Underflow"<<endl;
    }
    else{
        Node *t=new Node;
        t=front;
        front=front->next;
        x=t->data;
        delete t;
    }
    return x;
}

void Queue::display(){
    Node *p=front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

#endif