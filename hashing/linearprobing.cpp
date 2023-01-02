#include <iostream>
using namespace std;

#define SIZE 10

int hashfun(int key){
    return key%10;
}

int probe(int H[], int index){
    int i=0;
    while(H[(index+i)%SIZE]!=0){
        i++;
    }
    return (index+i)%SIZE;
}

void insert(int H[],int key){
    int index = hashfun(key);
    if(H[index]!=0){
        index = probe(H,index);
    }
    H[index] = key;
}

int search(int H[], int key){
    int index = hashfun(key);
    int i = 0;
    while(H[(index+i)%SIZE]!=key){
        if(H[(index + i)%SIZE]==0){
            return -1;
        }
        i++;
    }
    return (index+i)%SIZE;
}

int main(){
    int HT[SIZE];
    for(int i=0;i<SIZE;i++){
        HT[i]=0;
    }

    insert(HT,44);
    insert(HT,34);
    insert(HT,45);
    insert(HT,24);
    insert(HT,11);

    cout<<"Element found at index "<<search(HT,450);
}