#include <iostream>
#include "queue.h"
#include "stack.h"
using namespace std;

class Tree{
    public:
    Node *root;
    Tree(){
        root=NULL;
    }
    void CreateTree();
    void Preorder(Node *p);
    void Postorder(Node *p);
    void Inorder(Node *p);
    void Levelorder(Node *p);
    int Height(Node *root);
    void IPreorder(Node *p);
    void IInorder(Node *p);
    void IPostorder(Node *p);
    int count(Node *p);

};

void Tree::CreateTree(){
    Node *p,*t;
    int x;
    Queue q(100);

    cout<<"Enter root value: ";
    cin>>x;
    root = new Node;
    root->data = x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);

    while(!q.isEmpty()){
        p=q.dequeue();
        cout<<"Enter left child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data = x;
            t->lchild=t->rchild=NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout<<"Enter right child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data  = x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p){
    if(p){
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

int Tree::Height(Node *p){
    int x=0,y=0;
    if(!p){
        return 0;
    }
    x=Height(p->lchild);
    y=Height(p->rchild);
    if(x>y){
        return x+1;
    }
    else{
        return y+1;
    }
}

void Tree::Levelorder(Node *p){
    Queue q(100);
    cout<<p->data<<" ";
    q.enqueue(p);

    while(!q.isEmpty()){
        p=q.dequeue();
        if(p->lchild){
            cout<<p->lchild->data<<" ";
            q.enqueue(p->lchild);
        }
        if(p->rchild){
            cout<<p->rchild->data<<" ";
            q.enqueue(p->rchild);
        }
    }
}

void Tree::IPreorder(Node *p){
    Stack s(100);
    while(p||!s.isEmpty()){
        if(p){
            cout<<p->data<<" ";
            s.push(p);
            p=p->lchild;
        }else{
            p=s.pop();
            p=p->rchild;
        }
    }
}
void Tree::IInorder(Node *p){
    Stack s(100);
    while(p||!s.isEmpty()){
        if(p){
            s.push(p);
            p=p->lchild;
        }else{
            p=s.pop();
            cout<<p->data<<" ";
            p=p->rchild;
        }
    }
}

void Tree::IPostorder(Node *p){
    Stack s(100);
    intptr_t temp;
    while(p||!s.isEmpty()){
        if(p){
            s.push(p);
            p=p->lchild;
        }else{
            temp=(intptr_t)s.pop();
            if(temp>0){
                s.push((Node*)-temp);
                p=((Node*)temp)->rchild;
            }else{
                cout<<((Node*)(-1*temp))->data<<" ";
                p=NULL;
            }
        }
    }
}

int Tree::count(Node *p){
    if(p){
        return count(p->lchild)+count(p->rchild)+1;
    }
    return 0;
}

int main(){
    Tree t;
    t.CreateTree();
    cout<<"Preorder:  ";
    t.IPreorder(t.root);
    cout<<endl;
    cout<<"Inorder:   ";
    t.IInorder(t.root);
    cout<<endl;
    cout<<"Postorder:  ";
    t.IPostorder(t.root);
    cout<<endl;
    return 0;
}
