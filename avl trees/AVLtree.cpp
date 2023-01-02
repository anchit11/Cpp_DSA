#include <iostream>
using namespace std;
class Node{
    public:
    Node *lchild;
    Node *rchild;
    int height;
    int data;
};
class AVL{
    public:
    Node* root;
    AVL(){
        root=NULL;
    }
    Node * Rinsert(Node * p,int key);
    void Inorder(Node *p);
    void Inorder(){Inorder(root);}
    Node * getroot(){return root;}

    int NodeHeight(Node *p);
    int BalanceFactor(Node *p);
    Node* LLRotation(Node *p);
    Node * LRRotation(Node *p);
    Node *RRRotation(Node *p);
    Node * RLRotation(Node *p);
    Node *Delete(Node *p, int key);
    Node *InPre(Node *p);
    Node *InSucc(Node *p);
};

Node * AVL::Rinsert(Node * p,int key){
    Node* t=NULL;
    if(!p){
        t=new Node;
        t->data = key;
        t->height = 1; //Starting height from 1 instead of 0
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key<p->data){
        p->lchild = Rinsert(p->lchild, key);
    }else if(key>p->data){
        p->rchild = Rinsert(p->rchild, key);
    }
    p->height = NodeHeight(p);

    if(BalanceFactor(p)==2  && BalanceFactor(p->lchild)==1){
        return LLRotation(p);
    } else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1){
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
        return RLRotation(p);   
    }
    return p;
}

int AVL::BalanceFactor(Node *p){
    int hl;
    int hr;

    hl= (p&&p->lchild)?p->lchild->height:0;
    hr = (p&&p->rchild)? p->rchild->height : 0;

    return hl-hr;
}

int AVL::NodeHeight(Node *p){
    int hl, hr;
    hl= (p&&p->lchild)?p->lchild->height:0;
    hr = (p&&p->rchild)? p->rchild->height : 0;

    return hl>hr? hl+1:hr+1;
    
}

Node * AVL::LLRotation(Node *p){
    Node *pl = p->lchild, *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root = p){
        root = pl;
    }
    return pl;
}

Node* AVL::RRRotation(Node *p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;
 
    pr->lchild = p;
    p->rchild = prl;
 
    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
 
    // Update root
    if (root == p){
        root = pr;
    }
    return pr;
}

Node * AVL::LRRotation(Node *p){
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild =pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height= NodeHeight(plr);

    if(p==root){
        root = plr;
    }
    return plr;

}

Node* AVL::RLRotation(Node *p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;
 
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
 
    prl->rchild = pr;
    prl->lchild = p;
 
    // Update height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);
 
    // Update root
    if (root == p){
        root = prl;
    }
    return prl;
}

Node *AVL::InPre(Node *p){
    while(p&&p->rchild){
        p=p->rchild;
    }
    return p;
}

Node* AVL::InSucc(Node *p){
    while(p&&p->lchild){
        p=p->lchild;
    }
    return p;
}

void AVL::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}
Node* AVL::Delete(Node *p, int key) {
    if (p == nullptr){
        return nullptr;
    }
 
    if (p->lchild == nullptr && p->rchild == nullptr){
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
 
    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        Node* q;
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
 
    // Update height
    p->height = NodeHeight(p);
 
    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {  // L1 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){  // L-1 Rotation
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){  // R-1 Rotation
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){  // R1 Rotation
        return RLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0){  // L0 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0){  // R0 Rotation
        return RRRotation(p);
    }
    return p;
}
 
 
int main() {
 
    // LR Rotation
    AVL tlr;
    tlr.root = tlr.Rinsert(tlr.root, 50);
    tlr.root = tlr.Rinsert(tlr.root, 10);
    tlr.root = tlr.Rinsert(tlr.root, 20);
 
 
    tlr.Inorder();
    cout << endl;
    cout << tlr.root->data << endl;
 
    // RL Rotation
    AVL trl;
    trl.root = trl.Rinsert(trl.root, 20);
    trl.root = trl.Rinsert(trl.root, 50);
    trl.root = trl.Rinsert(trl.root, 30);
 
 
    trl.Inorder();
    cout << endl;
    cout << trl.root->data << endl;
 
    return 0;
}

