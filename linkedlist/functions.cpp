#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class LinkedList{
    private:
    Node *first;

    public:

    LinkedList(){
        first = NULL;
    }
    Node *getpointer(){
        return first;
    }
    void setpointer(Node* f){
        first =f;
    }
    LinkedList(int a[],int n);
    void display();
    void RecursiveDisplay(Node *p);
    int count();
    int Rsum(Node *p);
    int min();
    int rmax(Node *p);
    Node *Lsearch(int key);
    Node *ImprovedSearch(int key);
    void insert(int index, int element);
    void InsertSorted(int element);
    int Delete(int index);
    bool issorted();
    void RemoveDuplicate();
    void ReverseElements(); //using an auxiliary array
    void Reverse();         //using sliding pointer (3 pointers)
    void RecursiveReverse(Node *p,Node *q);
    void concat(LinkedList l);
    void merge(LinkedList l);
    bool isloop();
};
bool LinkedList::isloop(){
    Node *p,*q;
    p=q=first;
    do{
        p=p->next;
        q=q->next;
        q=q!=0?q->next:q;
    }
    while(p&&q&&p!=q);
    if(p==q){
        return true;
    }
    else{
        return false;
    }
}
void LinkedList::merge(LinkedList l){
    Node *p,*q,*third,*last;
    third=last=NULL;
    p=first;
    q=l.getpointer();
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        last->next = NULL;
    }
    else if(p->data > q->data){
        third=last=q;
        q=q->next;
        last->next = NULL;
    }
    else{
        third=last = p;
        p=p->next;
        q=q->next;
        last->next = NULL;
    }
    this->setpointer(third);
    l.setpointer(third);
    while(p&&q){
        if(p->data<q->data){
            last->next = p;
            last = p;
            p=p->next;
            last->next =NULL;
        }
        else if(p->data>q->data){
            last->next =q;
            last=q;
            q=q->next;
            last->next = NULL;
        }
        else{
            last->next = p;
            last =p;
            p=p->next;
            q=q->next;
            last->next = NULL;
        }
    }
    if(p){last->next = p;}
    else if(q){last->next = q;}
}
void LinkedList::concat(LinkedList l){
    Node *p,*q;
    p=first;
    q=l.getpointer();
    while(p->next){
        p=p->next;
    }
    p->next =q;
}
void LinkedList::RecursiveReverse(Node *p, Node *q=NULL){
    if(p){
        RecursiveReverse(p->next,p);
        p->next = q;
    }
    else{
        first = q;
    }
}

void LinkedList::Reverse(){
    Node *p,*q,*r;
    p=first;
    q=r=NULL;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first = q;
}
void LinkedList::ReverseElements(){
    Node *p=first;
    Node*q=first;
    int *A;
    int i=0;
    A = new int[this->count()];
    while(p){
        A[i++]=p->data;
        p=p->next;
    }
    p=q;
    i--;
    while(p){
        p->data=A[i--];
        p=p->next;
    }
}
void LinkedList::RemoveDuplicate(){
    Node *p=first;
    Node *q=first->next;
    while(q){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}
bool LinkedList::issorted(){
    Node *p = first;
    int x= INT_MIN;
    while(p){
        if(p->data<x){
            return false;
        }
        x=p->data;
        p=p->next;
    }
    return true;
}
int LinkedList::Delete(int index){
    if(index<1 ||index>this->count()){
        return -1;
    }
    Node *p, *q;
    int x;
    p = first;
    q=NULL;
    if(index==1){
        q=first;
        x=q->data;
        first = first->next;
        delete q;
        return x;
    }
    else{
        for(int i =0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x=p->data;
        delete p;
        return x;
    }
}
void LinkedList::InsertSorted(int element){
    Node *t,*p;
    Node *q=NULL;
    t=new Node;
    t->data = element;
    t->next = NULL;
    if(first ==NULL){
        first =  t;
    }
    else{
        p=first;
        while(p&&p->data<element){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next =first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}
void LinkedList::insert(int index, int element){
    if(index<0 || index>this->count()){
        return;
    }
    else{
        Node *t = new Node;
        t->data= element;
        t->next = NULL;
        if(first==NULL){
            first = t;
        }
        if(index ==0){
            t->next = first;
            first = t;
        }
        else{
            Node *p=first;
            for(int i =0;i<index-1&&p;i++){
                p=p->next;
            }
            t->next = p->next;
            p->next=t;
        }
    }
}

Node * LinkedList::Lsearch(int key){
    Node *p = first;
    while(p!=0){
        if(p->data == key){
            return p;
        }
        p=p->next;
    }
    return NULL;
}
Node * LinkedList::ImprovedSearch(int key){
    Node *p,*q;
    p=first;
    q=NULL;
    while(p!=0){
        if(p->data == key){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

LinkedList::LinkedList(int a[],int n){
    first = new Node;
    Node *last, *t;
    int i =0;
    //creating first node

    first->data = a[0];
    first->next = NULL;
    last = first;

    for(i =1;i< n;i++){
        t=new Node;
        t->data = a[i];
        t->next=NULL;
        last->next = t;
        last = t;
    }
}
 

void LinkedList::RecursiveDisplay(Node *p){
    if(p!=NULL){
        cout<<p->data<<" ";
        RecursiveDisplay(p->next);
    }
}

int LinkedList::count(){
    int c =0;
    Node *p= first;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}
//using recursion
int LinkedList::Rsum(Node *p){
    if(p){
        return Rsum(p->next)+p->data;
    }
    else{
        return 0;
    }
}

int LinkedList::min(){
    Node *p=first;
    int m = INT_MAX;
    while(p){
        if(p->data < m){
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

int LinkedList::rmax(Node *p){
    int x = 0;
    if(!p){
        return 0;
    }
    x = rmax(p->next);
    if(x>p->data){
        return x;
    }
    else{
        return p->data;
    }
}
void LinkedList::display(){
    Node *p = first;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main(){
    Node *p,*q;
    int A[]={2,4,6,7,10};
    int B[]={1,3,5,5,9};
    LinkedList l(A,5);
    p=l.getpointer()->next;
    q=l.getpointer()->next->next->next->next;
    q->next = p;
    if(l.isloop()){
        cout<<"List is looped"<<endl;
    }
    else{
    l.display();
    }
    
}

