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
int linearsearch(struct Array *arr, int key){
    for(int i=0;i<arr->length;i++){
        if(arr->A[i]==key){
            //for improving efficiency of linear search
            swap(arr->A[i],arr->A[i-1]);
            return i-1;
        }
    }
    return -1;
}
int main(){
    struct Array arr1={{2,3,4,5,6},10,5};
    
    cout<<"Element found at index: "<<linearsearch(&arr1,3)<<endl;
    Display(arr1);
    
    return 0;
}