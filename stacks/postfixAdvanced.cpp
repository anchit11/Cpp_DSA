#include <iostream>
#include <cstring>
using namespace std;

class Node{
    public:
    char data;
    Node *next;
};

class Parenthesis{
    private:
    Node *top;

    public:
    Parenthesis(){
        top=NULL;
    }
    void display();
    char getTop(){return top->data;}
    void push(char x);
    char pop();
    bool isEmpty();
    bool matching(string s);
    char* postfix(string s);
};

bool Parenthesis::isEmpty(){
    if(top){
        return false;
    }
    return true;
}
void Parenthesis::display(){
    Node *p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void Parenthesis::push(char x){
    Node *t=new Node;
    t->data =x;
    t->next = top;
    top =t;
}

char Parenthesis::pop(){
    if(isEmpty()){
        return '~';
    }
    else{
        char a;
        Node *t=new Node;
        t=top;
        a=t->data;
        top=top->next;
        delete t;
        return a;
    }
}

bool Parenthesis::matching(string s){
    char x;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            push(s[i]);
        }
        else if(s[i]==')'||s[i]=='}'||s[i]==']'){
            if(isEmpty()){
                return false;
            }
            else{
                x=top->data;
                if(s[i]==')'){
                    if(x=='('){
                        pop();
                    }else{
                        return false;
                    }
                }else if(s[i]==']'){
                    if(x=='['){
                        pop();
                    }else{
                        return false;
                    }
                }else{
                    if(x=='{'){
                        pop();
                    }else{
                        return false;
                    }
                }
            }    
        }
    }
    if(isEmpty()){
        return true;
    }
    return false;
}
int preI(char x){
    if(x=='+'||x=='-'){
        return 2;
    }else if(x=='*'||x=='/'){
        return 4;
    }else if(x=='^'){
        return 5;
    }else if(x=='('){
        return 0;
    }else{
        return -1;
    }
}
int preO(char x){
    if(x=='+'||x=='-'){
        return 1;
    }else if(x=='*'||x=='/'){
        return 3;
    }else if(x=='^'){
        return 6;
    }else if(x=='('){
        return 7;
    }else if(x==')'){
        return 0;
    }else{
        return -1;
    }
}
bool isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')'){
        return false;
    }
    return true;
}

char* Parenthesis::postfix(string s){
    char* post = new char[s.length()+1];
    int i,j;
    i=j=0;
    while(s[i]!='\0'){
        if(isOperand(s[i])){
            post[j++]=s[i++];
        }
        else{
            if(isEmpty()||preO(s[i])>preI(getTop())){
                push(s[i++]);
            }
            else if(preO(s[i])==preI(getTop())){
                pop();
            }
            else{
                post[j++]=pop();
            }
        }
    }
    while(top!=NULL&&getTop()!=')'){
        post[j++]=pop();
    }
    post[j]='\0';
    return  post;
}

int main(){
    Parenthesis s;
    string x = "((a+b)*c)-(d^e)*a^f";
    cout<<s.postfix(x);

}