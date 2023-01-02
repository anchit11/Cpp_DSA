#include <iostream>
using namespace std;

int fact(int n){
    if(n>=1){
        return fact(n-1)*n;
    }
    else{
        return 1;
    }
}
int main(){
    int x = 5;
    cout<<fact(x)<<endl;
    return 0;
}