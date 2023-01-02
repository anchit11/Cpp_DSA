#include <iostream>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void Selection(int A[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(A[k]>A[j]){
                k=j;
            }
        }
        swap(A[i],A[k]);
    }
}

int main(){
    int A[]={5,78,45,93,867,987,345,73,9,87};
    int n = sizeof(A)/sizeof(int);

    Selection(A,n);

    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}