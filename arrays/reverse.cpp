#include <iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};
void Display(struct Array arr){
    int i;
    cout<<"Elements are: ";
    for(i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

void reverse(struct Array *arr){
    for(int i=0;i<arr->length/2;i++){
        swap(arr->A[i],arr->A[(*arr).length-1-i]);
    }
}
int main(){
    struct Array arr1={{2,3,4,5,6,7},10,6};
    Display(arr1);
    reverse(&arr1);
    cout<<"After reversing ";
    Display(arr1);
    
    return 0;
}