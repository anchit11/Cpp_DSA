#include <iostream>

using namespace std;

void tower(int n,int a, int b,int c){
    if(n>0){
        tower(n-1,a,c,b);
        cout<<"From "<<a<<" to "<<c<<endl;
        tower(n-1,b,a,c);
    }
}
int main(){
    tower(3,1,2,3);
    
}