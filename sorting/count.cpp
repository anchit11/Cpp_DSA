#include <iostream>
using namespace std;

int findMax(int A[], int n){
    int c=INT32_MIN;
    for(int i = 0;i<n;i++){
        if(A[i]>c){
            c=A[i];
        }
    }
    return c;
}

void countSort(int A[],int n){
    int max;
    max = findMax(A,n);
    int *p;
    p= new int[max+1];
    for(int i = 0;i<n;i++){
        p[i] = 0;
    }
    for(int i=0;i<n;i++){
        p[A[i]]++;
    }
    int i = 0,j=0;
    while(i<max+1){
        if(p[i]>0){
            A[j++]=i;
            p[i]--;
        }else{
            i++;
        }
    }
}

int main(){
    int A[] = {8,3,7,4,9,2,6,5,1},n=9;
    countSort(A,9);
    for(int i =0;i<n;i++){
        cout<<A[i]<<" ";
    }cout<<endl;
}