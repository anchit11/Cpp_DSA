#include <iostream>
using namespace std;

void pairs(int arr[],int length){
    int i,j;
    i=0;
    j=length-1;
    while (i<j){
        if(arr[i]+arr[j]==10){
            cout<<arr[i++]<<","<<arr[j--]<<endl;
        }
        else if(arr[i]+arr[j]<10){
            i++;
        }
        else{
            j--;
        }
    }
}
int main(){
    int arr1[10]={1,2,3,5,6,7,8,9,10,11};
    pairs(arr1,10);
    return 0;
}