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
void lshift(struct Array *arr){
    for(int i=1;i<arr->length;i++){
        arr->A[i-1]=arr->A[i];
    }
    arr->A[arr->length-1]=0;
}
void rotation(struct Array *arr){
    int x= arr->A[0];
    for(int i=1;i<arr->length;i++){
        arr->A[i-1]=arr->A[i];
    }
    arr->A[arr->length-1]=x;
}

int main(){
    struct Array arr1={{2,3,4,5,6},10,5};
    Display(arr1);
    lshift(&arr1);
    rotation(&arr1);
    Display(arr1);
    return 0;
}