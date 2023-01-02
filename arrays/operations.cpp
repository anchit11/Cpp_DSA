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
int get(struct Array arr,int index){
    if(index>=0&& index<arr.length){
        return arr.A[index];
    }
    return -1;
}
void set(struct Array *arr, int index, int x){
    if(index>=0&& index<arr->length){
        arr->A[index]=x;
    }
}
int max(struct Array arr){
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]>max){
            max=arr.A[i];
        }
    }
    return max;
}
int min(struct Array arr){
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]<min){
            min= arr.A[i];
        }
    }
    return min;
}

int sum(struct Array arr){
    int sum =0;
    for(int i =0;i<arr.length;i++){
        sum+=arr.A[i];
    }
    return sum;
}

float avg(struct Array arr){
    float sum=0;
    for(int i=0;i<arr.length;i++){
        sum+=arr.A[i];
    }
    float avg=sum/arr.length;
    return avg;
}



int main(){
    struct Array arr1={{2,3,4,5,6},10,5};
    Display(arr1);
    set(&arr1,3,45);
    cout<<"Element at position: "<<get(arr1,3)<<endl;
    cout<<"Maximum: "<<max(arr1)<<endl;
    cout<<"Minimum: "<<min(arr1)<<endl;
    cout<<"Sum: "<<sum(arr1)<<endl;
    cout<<"Avg: "<<avg(arr1)<<endl;

    
    return 0;
}