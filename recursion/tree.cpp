#include <iostream>
using namespace std;

// tree recursion is when 2 or more than 2 recursion are used

void fun(int n){
    if(n>0){
        cout<<n<<endl;
        fun(n-1);
        fun(n-1);
    }
}
int main(){
    fun(3);
    return 0;
}