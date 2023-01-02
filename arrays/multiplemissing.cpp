#include <iostream>
using namespace std;

void missingsorted(int arr[],int length){
    int diff;
    diff = arr[0]-0;
    for(int i=0;i<length;i++){
        while((arr[i]-i)!=diff){
            cout<<" "<<i+diff;
            diff++;
        }
    }
}
int maximum(int arr[],int length){
    int max=arr[0];
    for(int i=1;i<length;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
int minimum(int arr[],int length){
    int min=arr[0];
    for(int i=1;i<length;i++){
        if(arr[i]<min){
            min= arr[i];
        }
    }
    return min;
}

// using hashing
void missingUnsorted(int arr[], int length){
    int max,min;
    max = maximum(arr,length);
    min = minimum(arr,length);
    int copy[max+1]={0};
    for(int i=0;i<length;i++){
        copy[arr[i]]++;
    }
    for(int i=min;i<=max;i++){
        if(copy[i]==0){
            cout<<i<<" ";
        }
    }
}

int main(){
    int arr1[10]={19,8,9,7,2,3,4,6};
    int arr2[10]={6,7,9,10,13,16};
    missingUnsorted(arr1,8);
    return 0;
}