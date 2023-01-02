#include <iostream>
using namespace std;

void duplicates(int arr[], int length){
    int lastduplicate=-1;
    for(int i=0;i<length-1;i++){
        if(arr[i]==arr[i+1]&& arr[i]!=lastduplicate){
            cout<<arr[i]<<" ";
            lastduplicate=arr[i];
        }
    }
}

void unsorted(int arr[],int length){
    
    for(int i=0;i<length;i++){
        int count =1;
        if(arr[i]==-1){
            continue;
        }
        for(int j = i+1;j<length;j++){
            if(arr[i]==arr[j]){
                count++;
                arr[j]=-1;
            }
        }
        if(count>1){
            cout<<arr[i]<<" : "<<count<<endl;
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
void hashingduplicates(int arr[],int length){
    int max,min;
    max = maximum(arr,length);
    min = minimum(arr,length);
    int copy[max+1]={0};
    for(int i=0;i<length;i++){
        copy[arr[i]]++;
    }
    for(int i=min;i<=max;i++){
        if(copy[i]>=2){
            cout<<i<<" : "<<copy[i]<<endl;
        }
    }
}
int main(){
    int arr1[10]={9,8,2,3,3,3,7,6,6,9};
    unsorted(arr1,10);
}