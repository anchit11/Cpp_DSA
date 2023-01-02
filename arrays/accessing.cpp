#include <iostream>
using namespace std;

int A[]={1,2,3,4,5};

int main(){
    std::cout<<*(A+2);
    int *p;
    p= new int[5];
    p[0]=1;
    cout<<p[0]<<&p[1]<<endl;

    //increasing size of array

    int *q= new int[10];
    for(int i =0;i<5;i++){
        q[i]=p[i];
    }
    delete []p;
    p=q;
    q=NULL;
    cout<<p[0]<<&p[1]<<&p[2]<<endl;
    return 0;
    
}