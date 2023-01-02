#include <iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};
void Display(struct Array arr){
    int i;
    cout<<"Elements are: "<<endl;
    for(i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}
void insertSort(struct Array *arr, int x){
    if(arr->length == arr->size){
        return;
    }
    int i= arr->length-1;
    while(arr->A[i]>x && i>=0){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

bool issorted(struct Array arr){
    for(int i = 0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            return false;
        }
    }
    return true;
}

void rearrange(struct Array *arr){
    int i=0;
    int j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0){i++;}
        while(arr->A[j]>=0){j--;}
        if(i<j){
            swap(arr->A[i],arr->A[j]);
        }
    }
}
int main(){
    struct Array arr1={{2,3,-9,4,5,-6},10,6};
    Display(arr1);
    insertSort(&arr1, 1);
    Display(arr1);
    if(issorted(arr1)){
        cout<<"Array is sorted"<<endl;
    }
    rearrange(&arr1);
    Display(arr1);
    return 0;
}