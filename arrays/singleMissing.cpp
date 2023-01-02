#include<iostream>
using namespace std;

int natural(int arr[],int length){
    int sum =0;
    for(int i=0;i<length;i++){
        sum+=arr[i];
    }
    int s = arr[length-1]*(arr[length-1]+1)/2;
    int x = s-sum;
    return x;
}
void missing(int arr[],int length){
    int diff;
    diff = arr[0]-0;
    for(int i=0;i<length;i++){
        if((arr[i]-i)!=diff){
            cout<<"Missing element is: "<<arr[i]-1;
            break;
        }
    }
}

int main(){
    int arr1[10]={1,2,3,4,6,7,8,9,10,11};
    int arr2[10]={6,7,8,9,10,12,13,14,15,16};
    // int element;
    // element = natural(arr1,10);
    // cout<<"Element: "<<element<<endl;
    missing(arr2,10);
    return 0;
}