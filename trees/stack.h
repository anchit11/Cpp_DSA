#include <iostream>
using namespace std;

#ifndef stack_h
#define stack_h

// class Node{
//     public:
//     Node *lchild;
//     Node *rchild;
//     int data;
// };

class Stack{
    private:
    int size;
    Node **A;
    int top;

    public:
    Stack(int size);
    void push(Node* x);
    Node * pop();
    void display();
    Node* peek(int index);
    bool isEmpty();
    bool isFull();
    Node* stackTop();
    ~Stack(){delete []A;}
};

Stack::Stack(int size){
    A=new Node*[size];
    this->size = size;
    top = -1;
}

void Stack::display(){
    for(int i=top;i>=0;i--){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void Stack::push(Node* x){
    if(top==size-1){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        top++;
        A[top]=x;
    }
}

Node * Stack::pop(){
    Node* x=NULL;
    if(top==-1){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        x=A[top--];
    }
    return x;
}

bool Stack::isEmpty(){
    if(top==-1){
        return true;
    }
    return false;
}

bool Stack::isFull(){
    if(top == size -1){
        return true;
    }
    return false;
}

Node* Stack::stackTop(){
    return A[top];
}

Node* Stack::peek(int index){
    Node * x=NULL;
    if(top-index+1<0){
        cout<<"Invalid Index" << endl;
    }
    x=A[top-index+1];
    return x;
}


#endif