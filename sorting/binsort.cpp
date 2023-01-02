#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};

int findMax(int A[], int n){
    int c=INT32_MIN;
    for(int i = 0;i<n;i++){
        if(A[i]>c){
            c=A[i];
        }
    }
    return c;
}

void Insert(Node **a, int x){
    
}

void binsort(int A[], int n){
    int max, i, j;
    Node **bins;
    max = findMax(A,n);
    bins = new Node *[max+1];
    for(i=0;i<=max;i++){
        bins[i]= NULL;
    }
    for(i=0;i<n;i++){
        //Insert(bins[A[i]],A[i]);
    }
    i=j=0;
    while(i<=max){
        while(bins[i]!=NULL){
           // A[j++]= Delete(bins[i]);
        }
        i++;
    }
}

int main(){
    return 0;
}