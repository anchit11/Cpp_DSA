#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
class Stack{
    public:
    Node *top;
    Stack(){
        top=NULL;
    }
    void push(int x);
    int pop();
    int stackTop();
    bool isEmpty();
    void display();
};
bool Stack::isEmpty(){
    if(top==NULL){
        return true;
    }
    return false;
}

void Stack::push(int x){
    Node *t=new Node;
    t->data = x;
    t->next = top;       //inserting in front due to constant time
    top=t;
}

int Stack::pop(){
    int x=-1;
    Node *t=new Node;
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        t=top;
        x=t->data;
        top=top->next;
        delete t;
    }
    return x;
}

int Stack::stackTop(){
    return top->data;
}

class Queue{
    public:
    Stack s1,s2;

//    public:
    Queue(){};

    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x){
    s1.push(x);
}
void Stack::display(){
    Node *p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int Queue::dequeue(){
    int x=-1;
    if(s2.isEmpty()){
        if(s1.isEmpty()){
            cout<<"Queue is Empty"<<endl;
        }
        else{
            Node *t=s1.top;
            while(t){
                x=s1.pop();
                s2.push(x);
                t=t->next;
            }
            x=s2.pop();
        }
    }
    else{
        x=s2.pop();
    }
    return x;
}



int main(){
    Queue q;
    q.enqueue(67);
    q.enqueue(4);
    q.enqueue(59);
    int c=1;
    q.dequeue();
    q.dequeue();
    q.enqueue(89);
    while(c<3){
        cout<<q.dequeue()<<endl;
        c++;
    }

}
