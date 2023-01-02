#include <iostream>
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

int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q;
 
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
    }
 
    // Display
    q.display();
 
    // Overflow
    q.enqueue(10);
 
    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout<<q.dequeue()<<endl;
    }
 
    // Underflow
    q.dequeue();
    q.dequeue();q.dequeue();q.dequeue();
    
    return 0;
}
