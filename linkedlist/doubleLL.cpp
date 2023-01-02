#include <iostream>
using namespace std;

class Node{
    public:
    Node * prev;
    int data;
    Node *next;
};

class DoubleLL{
    private:
    Node *first;

    public:

    Node * getpointer(){
        return first;
    }
    void setpointer(Node *f){
        first = f;
    }

    DoubleLL();
    DoubleLL(int a[],int n);
    int length();
    void display();
    void insert(int index, int x);
    void deleteLL(int index);
    void reverse();
};

DoubleLL::DoubleLL(){
    first = NULL;
}

DoubleLL::DoubleLL(int a[],int n){
    Node *last, *t;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    first->prev= NULL;
    last = first;
    for(int i =1;i<n;i++){
        t=new Node;
        t->data = a[i];
        t->next = NULL;
        t->prev=last;
        last->next =t;
        last = t;
    }
}

void DoubleLL::display(){
    Node *f=first;
    while(f){
        cout<<f->data<<" ";
        f=f->next;
    }
}

int DoubleLL::length(){
    int n =0;
    Node *p=first;
    while(p){
        n++;
        p=p->next;
    }
    return n;
}

void DoubleLL::insert(int index, int x){
    Node *p,*t;
    p=first;
    if(index<0||index>this->length()){
        return;
    }
    if(index==0){
        t=new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first =t ;
    }
    else{
        t=new Node;
        t->data = x;
        for(int i = 0;i<index-1;i++){
            p=p->next;
        }
        t->prev = p;
        t->next = p->next;
        if(p->next){
            p->next->prev=t;
        }
        p->next = t;
    }
}

void DoubleLL::deleteLL(int index){
    Node *p = first;
    if (index == 0)
    {
        if (p->next)
        {
            first = p->next;
            first->prev = NULL;
            delete p;
        }
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;

        delete p;
    }
}

void DoubleLL::reverse(){
    Node *p=first;
    Node *temp;
    while (p){
        temp=p->next;
        p->next = p->prev;
        p->prev = temp;
        p=p->prev;
        if(p&&p->next==NULL){
            first = p;
        }
    }
}
int main(){
    int A[] = {1, 5, 7, 10, 15, 18, 21,85};
    DoubleLL doub(A, sizeof(A) / sizeof(A[0]));
    doub.reverse();
    cout<<endl;
    doub.display();
}

 