#include <iostream>
using namespace std;

class Node{
    public:
    int col;
    int data;
    Node *next;
};

class SparseMatrix{
    private:
    int rows;
    Node *first;

    public:
    Node * getpointer(){
        return first;
    }
    void setpointer(Node* f){
        first = f;
    }
    SparseMatrix(int rows,int n);
    void display();
};
SparseMatrix::SparseMatrix(int rows,int n){
    Node *A[rows];
    first = A[0];
    for(int i=0;i<rows;i++){
        A[i]=new Node;
        A[i] = NULL;
    }
    Node *t;
    int row;
    for(int i=0;i<n;i++){
        t=new Node;
        t->next = NULL;
        cin>>row>>t->col>>t->data;
        if(A[row]==NULL){
            A[row]->next = t;
        }
        else{
            Node *p=A[row];
            while(p){
                p=p->next;
            }
            p->next = t;
        }
    }
}

void SparseMatrix::display(){
    Node *p=NULL;
    for(int i =0;i<rows;i++){
        p=
    }
}
int main(){
    return 0;
}