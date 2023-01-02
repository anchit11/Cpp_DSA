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
int binarysearch(struct Array arr, int key){
    int l=0;
    int h=arr.length-1;
    int mid;
    while(l<=h){
        mid= (l+h)/2;
        if(key==arr.A[mid]){
            return mid;
        }
        else if(arr.A[mid]>key){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}
int main(){
    struct Array arr1={{2,3,4,5,6},10,5};
    Display(arr1);
    cout<<"Element found at index: "<<binarysearch(arr1,5)<<endl;
    return 0;
}

/* using recursion
    algorithm search(l,h,key){
        if(l<=h)
        {
            mid;
            if(key=mid){
                return mid
            }
            else if(key<mid)
            return search(l,mid-1,key);
            else return search(mid+1,h,key);

        }
    }
*/