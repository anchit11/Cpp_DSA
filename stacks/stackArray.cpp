#include <iostream>
using namespace std;

class Stack{
    private:
    int size;
    int *A;
    int top;

    public:
    Stack(int size);
    void push(int x);
    int pop();
    void display();
    int peek(int index);
    bool isEmpty();
    bool isFull();
    int stackTop();
    ~Stack(){delete []A;}
};

Stack::Stack(int size){
    A=new int[size];
    this->size = size;
    top = -1;
}

void Stack::display(){
    for(int i=top;i>=0;i--){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void Stack::push(int x){
    if(top==size-1){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        top++;
        A[top]=x;
    }
}

int Stack::pop(){
    int x=-1;
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

int Stack::stackTop(){
    return A[top];
}

int Stack::peek(int index){
    int x=1;
    if(top-index+1<0){
        cout<<"Invalid Index" << endl;
    }
    x=A[top-index+1];
    return x;
}


int main(){
    int x;
    cout<<"Enter size of Stack: ";
    cin>>x;
    Stack s(x);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout<<s.peek(3);
    
}
