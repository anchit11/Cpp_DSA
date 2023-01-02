#include <iostream>
using namespace std;

class Node{
    public:
    Node *lchild;
    Node *rchild;
    int data;
};
class BST{
    private:
    Node *root;

    public:
    Node * getroot();
    BST(){root=NULL;}
    void insert(int key);
    Node * search(int key);
    void Inorder(Node *root);
    Node * Rinsert(Node *p,int key);
    void setroot(Node *p){
        root = p;
    }
    Node * Delete(Node *p,int key);
    int Height(Node *p);
    Node * InPre(Node *p);
    Node * InSucc(Node *p);
};

void BST::insert(int key){
    Node *p=root;
    Node *t=NULL,*q=NULL;
    if(root==NULL){
        t=new Node;
        t->data = key;
        t->lchild=t->rchild=NULL;
        root = t;
        return;
    }
    while(p){
        q=p;
        if(key<p->data){
            p=p->lchild;
        }
        else if(key>p->data){
            p=p->rchild;
        }else{
            return;
        }
    }
    t=new Node;
    t->data = key;
    t->lchild=t->rchild=NULL;
    if(key<q->data){
        q->lchild=t;
    }
    else{
        q->rchild=t;
    }
}
Node* BST::getroot(){
    return root;
}
void BST::Inorder(Node *root){
    if(root){
        Inorder(root->lchild);
        cout<<root->data<<" ";
        Inorder(root->rchild);
    }
}
Node * BST::search(int key){
    Node *p=root;
    while(p){
        if(key==p->data){
            return p;
        }
        else if(key<p->data){
            p=p->lchild;
        }else{
            p=p->rchild;
        }
    }
    return NULL;
}

Node * BST::Rinsert(Node *p,int key){
    Node *t=NULL;
    if(!p){
        t=new Node;
        t->data = key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data){
        p->lchild=Rinsert(p->lchild,key);
    }else if(key>p->data){
        p->rchild = Rinsert(p->rchild,key);
    }
    return p;
}
int BST::Height(Node *p){
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
Node *BST::InPre(Node *p){
    while(p&&p->rchild){
        p=p->rchild;
    }
    return p;
}

Node* BST::InSucc(Node *p){
    while(p&&p->lchild){
        p=p->lchild;
    }
    return p;
}
Node *BST::Delete(Node *p,int key){
    Node *q=NULL;
    if(!p){
        return NULL;
    }
    if(!p->lchild&&!p->rchild){
        if(p==root){
            root=NULL;
        }
        delete p;
        return NULL;
    }
    if(key<p->data){
        p->lchild=Delete(p->lchild,key);
    }else if(key>p->data){
        p->rchild=Delete(p->rchild,key);
    }else{
        //checking height of left subtree and right subtree and then deciding from  which end we should delete
        if(Height(p->lchild)>Height(p->rchild)){
            q=InPre(p->lchild);
            p->data = q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else{
            q=InSucc(p->rchild);
            p->data = q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }   
    return p;
}
int main(){
    BST tree;
    Node *p=tree.Rinsert(tree.getroot(),40);
    tree.setroot(p);
    tree.Rinsert(tree.getroot(),78);
    tree.Rinsert(tree.getroot(),34);
    tree.Rinsert(tree.getroot(),57);
    tree.Rinsert(tree.getroot(),38);
    tree.insert(56);
    tree.insert(990);
    tree.insert(53);
    tree.Delete(tree.getroot(),60);
    tree.Delete(tree.getroot(),34);
    tree.Inorder(tree.getroot());
    cout<<endl;
}





























