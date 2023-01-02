#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
class CircularLL{
    private:
    Node *head;
    public:
    Node *getpointer(){
        return head;
    }
    void setpointer(Node* f){
        head=f;
    }
    bool iscircular();
    void displayCircular();
    void rDisplayCircular(Node *h);
    CircularLL();
    CircularLL(int a[], int n);
    int length();
    void insert(int index, int x);
    int deleteLL(int index);
};

void CircularLL::insert(int index, int x){
    Node *h,*p;
    h=head;
    if(index<0||index>this->length()){
        return;
    }
    if(index==0){
        Node *t;
        t=new Node;
        t->data = x;
        if(head==NULL){
            head = t;
            head->next =head;
        }
        else{
            while(p->next!=head){
                p=p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else{
        for(int i = 0;i<index;i++){
            p=p->next;
        }
        Node *t;
        t= new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
int CircularLL::deleteLL(int index){
    Node *h,*p,*q;
    h=p=head;
    int x,i;
    if(index<0||index>this->length()){
        return -1;
    }
    if(index==0){
        while(p->next!=head){
            p=p->next;
        }
        x=head->data;
        if(head==p){
            delete head;
            head = NULL;
        }
        else{
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }q=p->next;
        p->next = q->next;
        x=q->data;
        delete q;
    }
    return x;
}
int CircularLL::length(){
    Node * h;
    h=head;
    int l=0;
    do{
        l++;
        h=h->next;
    }while(h!=head);
    return l;
}
CircularLL::CircularLL(){
    head = NULL;
}
CircularLL::CircularLL(int a[],int n){
    Node *last,*t;
    head = new Node;
    head->data = a[0];
    head->next = head;
    last = head;
    for(int i = 1;i<n;i++){
        t=new Node;
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last =t ;
    }
    
}

bool CircularLL::iscircular(){
    Node *p,*q;
    q=p=head;
    do{
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:q;
    }
    while(p&&&q&&p!=q);
    if(p==q){
        return true;
    }
    else{
        return false;
    }
}

void CircularLL::displayCircular(){
    Node *h;
    h=head;
    do{
        cout<<h->data<<" ";
        h=h->next;
    }while(h!=head);
    cout<<endl;
}

void CircularLL::rDisplayCircular(Node *h){
    static int flag = 0;
    if(h!=head||flag==0){
        flag=1;
        cout<<h->data<<" ";
        rDisplayCircular(h->next);
    }
    flag = 0;
}
int main(){
    int A[]={1,2,3,4,5,6};
    CircularLL c(A,6);
    c.rDisplayCircular(c.getpointer());
    c.insert(0,7);
    cout<<endl;
    c.displayCircular();
    cout<<endl<<c.deleteLL(0);
    cout<<endl;
    c.displayCircular();
}
