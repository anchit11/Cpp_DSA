#include <iostream>
using namespace std;

void Insertion(int A[],int n){
    int i,j,x;
    for(i=1;i<n;i++){
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}


int main(){
    //int A[]={5,78,45,93,867,987,345,73,9,87};
    int A[] = {76,89,45,36,11,8,67,90,54,79};
    int n = sizeof(A)/sizeof(int);

    Insertion(A,n);

    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}