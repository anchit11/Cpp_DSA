#ifndef linkedlist_h
#define linkedlist_h
#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void InsertSorted(Node **h, int element){
    Node *t,*p;
    Node *q=NULL;
    t=new Node; 
    t->data = element;
    t->next = NULL;
    if(*h ==NULL){
        *h =  t;
    }
    else{
        p=*h;
        while(p&&p->data<element){
            q=p;
            p=p->next;
        }
        if(p==*h){
            t->next =*h;
            *h = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}
Node * Lsearch(Node *h,int key){
    Node *p = h;
    while(p!=NULL){
        if(p->data == key){
            return p;
        }
        p=p->next;
    }
    return NULL;
}


#endif

