#include <iostream>

using namespace std;

void MergeSingle(int A[], int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int B[high+1];
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid){
        B[k++] = A[i++];
    }
    while (j <= high){
        B[k++] = A[j++];
    }
    for (int i=low; i<=high; i++){
        A[i] = B[i];
    }
}

void IMergeSort(int A[], int n){
    int p,i,l,mid,h;

    for(p=2;p<=n;p=p*2){
        for(i=0;i+p-1<n;i+=p){
            l=i;
            h=i+p-1;
            mid = (l+h)/2;
            MergeSingle(A,l,mid,h);
        }
    }
    if(p/2<n){
        MergeSingle(A,0,p/2-1,n-1);
    }
}

int Mergesort(int A[], int l, int h){
    int mid;
    if(l<h){
        mid = (l+h)/2;
        Mergesort(A,l,mid);
        Mergesort(A,mid+1,h);
        MergeSingle(A,l,mid,h);
    }
}

int main(){
    //int A[] = {8,3,7,4,9,2,6,5,1},n=9;
    int A[] = {76,89,45,36,11,8,67,90,54,79},n=10;
    Mergesort(A,0,9);
    for(int i =0;i<n;i++){
        cout<<A[i]<<" ";
    }cout<<endl;
}