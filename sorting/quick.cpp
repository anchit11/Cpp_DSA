#include <iostream>
using namespace std;


int partition( int A[], int l, int h){
    int pivot = A[l];
    int i = l, j = h;
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j){
            swap(A[i],A[j]);
        }
    }while(i<j);
    swap(A[j],A[l]);
    return j;
}

void Quicksort(int A[], int l, int h){
    int j;
    if(l<h){
        j=partition(A,l,h);
        Quicksort(A,l,j);
        Quicksort(A,j+1,h);
    }
}
int main(){
    int A[]={87,45,83,90,53,37,39,59,37,10,INT32_MAX};
    int B[] = {76,89,45,36,11,8,67,90,54,79,INT32_MAX};
    Quicksort(B,0,10);

    cout<<"Sorted array is: ";
    for(int i=0;i<10;i++){
        cout<<B[i]<<" ";
    }
    cout<<endl;
    return 0;
}