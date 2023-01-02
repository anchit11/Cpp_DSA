#include <iostream>
#include "linkedlist.h"

using namespace std;

int hashfun(int key){
    return key%10;
}
void insert(Node *h[], int key){
    int index = hashfun(key);
    InsertSorted(&h[index],key);
}
int main(){
    Node * HT[10];
    Node *temp;
    int i;
    for(i=0;i<10;i++){
        HT[i] = NULL;
    }
    insert(HT,12);
    insert(HT,22);
    insert(HT,24);

    temp = Lsearch(HT[hashfun(24)],24);

    cout<<temp->data;

    return 0;
}