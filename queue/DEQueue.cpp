//Double Ended Queue
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
class DEQueue{
    private:
    Node *front;
    Node *rear;

    public:
    DEQueue(){
        front = rear = NULL;
    }
    void enqueueF(int x);
    void enqueueR(int x);
    int dequeueF();
    int dequeueR();
    bool isEmpty();
    void display();
    int count();
};
int DEQueue::count(){
    int c=0;
    Node *p=front;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}
bool DEQueue::isEmpty(){
    if(front==NULL){
        return true;
    }
    return false;
}

void DEQueue::enqueueF(int x){
    Node *t=new Node;
    t->data = x;
    t->next = NULL;
    if(isEmpty()){
        front=rear=t;
    }
    else{
        t->next = front;
        front = t;
    }
}

void DEQueue::enqueueR(int x){
    Node *t=new Node;
    t->data = x;
    t->next = NULL;
    if(isEmpty()){
        front = rear = t;
    }
    else{
        rear->next = t;
        rear = t;
    }
}

int DEQueue::dequeueF(){
    int x=-1;
    Node *t=new Node;
    if(isEmpty()){
        cout<<"Queue Underflow"<<endl;
    }
    else{
        t=front;
        front = front->next;
        x=t->data;
        delete t;
    }
    return x;
}

int DEQueue::dequeueR(){
    int x=-1;
    Node *t=new Node;
    if(isEmpty()){
        cout<<"Queue Underflow"<<endl;
    }
    else{
        t=front;
        for(int i=0;i<count()-2;i++){
            t=t->next;
        }
        x=rear->data;
        rear = t;
        rear->next = NULL;
    }
    return x;
}

void DEQueue::display(){
    Node *p=front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    DEQueue q;
    q.enqueueF(4);
    q.enqueueR(5);
    q.enqueueF(7);
    q.enqueueF(8);
    q.enqueueR(10);
    q.enqueueR(68);
    q.enqueueF(56);
    q.display();
    cout<<q.dequeueF()<<endl;
    cout<<q.dequeueR()<<endl;
    cout<<q.dequeueR()<<endl;
    q.display();
}
