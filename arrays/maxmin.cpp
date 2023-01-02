#include <iostream>
using namespace std;

void minmax(int arr[],int length){
    int min,max;
    min=max=arr[0];
    for(int i=0;i<length;i++){
        if(arr[i]<min){
            min=arr[i];
        }
        else if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<"Max & Min : "<<max<<" "<<min<<endl;
}
int main(){
    int arr[]={9,7,5,8,6,3,10,75,84,25,36,41};
    minmax(arr,12);
    return 0;
}
