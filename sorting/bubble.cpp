#include <iostream>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void Bubble(int A[],int n){
    int flag,i,j;
    for(i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                swap(&A[j],&A[j+1]);
                flag = 1;
            }
        }
        if(!flag){
            return;
        }
    }
}

int main(){
    int A[]={5,78,45,93,867,987,345,73,9,87};
    int n = sizeof(A)/sizeof(int);

    Bubble(A,n);

    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}