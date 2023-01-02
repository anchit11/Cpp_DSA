#include <iostream>
using namespace std;

void pairs(int arr[],int length){
    for(int i=0;i<length -1;i++){
        for(int j=i+1;j<length;j++){
            if(arr[i]+arr[j]==10){
                cout<<arr[i]<<","<<arr[j]<<endl;
            }
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

void pairsHashing(int arr[],int length){
    int max,min;
    max = maximum(arr,length);
    min = minimum(arr,length);
    int copy[max+1]={0};
    for(int i=0;i<length;i++){
        if(copy[10-arr[i]]!=0){
            cout<<arr[i]<<","<<10-arr[i]<<endl;
        }
        copy[arr[i]]++;
    }

}
int main(){
    int arr1[10]={8,1,9,4,5,6,2,3,11,7};
    pairsHashing(arr1,10);
    return 0;
}