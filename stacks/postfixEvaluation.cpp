#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class Stack{
    private:
    Node *top;

    public:
    Stack(){
        top=NULL;
    }
    void display();
    void push(int x);
    int pop();
    int peek(int pos);
    bool isEmpty();
    bool isFull();
    int stackTop();
    int eval(string s);
};

bool isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'){
        return false;
    }
    return true;
}

void Stack::display(){
    Node *p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void Stack::push(int x){
    Node *t=new Node;
    if(t==NULL){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop(){
    int x=-1;
    if(!top){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        Node *t = top;
        x=t->data;
        top=top->next;
        delete t;
    }
    return x;
}   

int Stack::peek(int pos){
    int x=-1;
    Node *t=top;
    for(int i=1;i<pos&&t;i++){
        t=t->next;
    }
    x=t->data;
    return x;
}

bool Stack::isEmpty(){
    if(top==NULL){
        return true;
    }
    return false;
}

bool Stack::isFull(){
    Node *t=new Node;
    if(!t){
        return true;
    }
    return false;
}

int Stack::stackTop(){
    if(isEmpty()){
        return -1;
    }
    else{
        return top->data;
    }
}

int Stack::eval(string s){
    int a,b,i,result = 0;
    for(i=0;s[i]!='\0';i++){
        if(isOperand(s[i])){
            push(s[i]-'0'); //converting char to required integer number
        }
        else{
            b=pop();
            a=pop();
            switch(s[i]){
                case '+':
                result=a+b;
                break;

                case '-':
                result=a-b;
                break;

                case '*':
                result = a*b;
                break;

                case '/':
                result=a/b;
                break;
            }
            push(result);
        }

    }
    return top->data;
}

int main(){
    Stack s;

    string postfix="234*+82/-";
    cout<<s.eval(postfix);
}